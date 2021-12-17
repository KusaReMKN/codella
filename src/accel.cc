#include "accel.hh"

const char *const armadillo::accel::DELAY_PATH =
	"/sys/devices/platform/i2c-sh_mobile.1/i2c-1/1-004c/delay";
const char * const armadillo::accel::ENABLE_PATH =
	"/sys/devices/platform/i2c-sh_mobile.1/i2c-1/1-004c/enable";
const char * const armadillo::accel::EVENT_PATH =
	"/dev/input/event2";

double const armadillo::accel::SENSITIVITY = 2.133;

void *armadillo::accel::event_loop(void *me)
{
	armadillo::accel *self = (armadillo::accel *)me;
	self->read_flag = NONE;

	self->set_sensor(true);
	while (self->enabled)
		self->read_event();
	self->set_sensor(false);

	return NULL;
}

void armadillo::accel::set_sensor(bool on)
{
	int err;
	err = dprintf(enable_file, "%c", on ? '1' : '0');
	if (err < 0)
		throw std::runtime_error(armadillo::errmsg("dprintf"));
}

void armadillo::accel::read_event()
{
	struct input_event ev;
	int err;
	err = read(event_file, &ev, sizeof(ev));
	if (err == -1)
		throw std::runtime_error(armadillo::errmsg("read"));

	switch (ev.type) {
	case EV_ABS:
		switch (ev.code) {
		case ABS_X:
			temp.x = ev.value;
			read_flag |= X_READ;
			break;
		case ABS_Y:
			temp.y = ev.value;
			read_flag |= Y_READ;
			break;
		case ABS_Z:
			temp.z = ev.value;
			read_flag |= Z_READ;
			break;
		default:
			throw std::runtime_error(
				armadillo::errmsg("Invalid Event Type"));
		}
		break;
	case EV_SYN:
		if (read_flag == ALL_READ) {
			int err;
			err = pthread_mutex_lock(&value_mutex);
			if (err != 0)
				throw std::runtime_error(
					armadillo::errmsg(
						"pthread_mutex_lock", err));
			value = temp;
			err = pthread_mutex_unlock(&value_mutex);
			if (err != 0)
				throw std::runtime_error(
					armadillo::errmsg(
						"pthread_mutex_unlock", err));
		}
		break;
	default:
		throw std::runtime_error(
			armadillo::errmsg("Invalid Event Type"));
	}
}

int armadillo::accel::get_raw_value(int *x, int *y, int *z)
{
	if (read_flag != ALL_READ)
		return -1;

	int err;
	err = pthread_mutex_lock(&value_mutex);
	if (err != 0)
		throw std::runtime_error(
			armadillo::errmsg("pthread_mutex_lock", err));
	*x = value.x / 47;
	*y = value.y / 47;
	*z = value.z / 47;
	err = pthread_mutex_unlock(&value_mutex);
	if (err != 0)
		throw std::runtime_error(
			armadillo::errmsg("pthread_mutex_unlock", err));

	read_flag = NONE;

	return 0;
}

armadillo::accel::accel():
	enabled(false), delay(1)
{
	delay_file = open(DELAY_PATH, O_WRONLY);
	if (delay_file == -1)
		throw std::runtime_error(armadillo::errmsg("open: DELAY"));
	enable_file = open(ENABLE_PATH, O_WRONLY);
	if (enable_file == -1)
		throw std::runtime_error(armadillo::errmsg("open: ENABLE"));
	event_file = open(EVENT_PATH, O_RDONLY);
	if (event_file == -1)
		throw std::runtime_error(armadillo::errmsg("open: EVENT"));

	set_delay(delay);
}

armadillo::accel::~accel()
{
	close(delay_file);
	close(enable_file);
	close(event_file);
}

void armadillo::accel::enable()
{
	enabled = true;
	pthread_mutex_init(&value_mutex, NULL);
	int err;
	err = pthread_create(&event_thread, NULL, event_loop, this);
	if (err != 0)
		throw std::runtime_error(
			armadillo::errmsg("pthread_create", err));
}

void armadillo::accel::disable()
{
	enabled = false;
	int err;
	err = pthread_join(event_thread, NULL);
	if (err != 0)
		throw std::runtime_error(
			armadillo::errmsg("pthread_join", err));
}

void armadillo::accel::set_delay(unsigned int d)
{
	int err;
	err = dprintf(delay_file, "%u", d);
	if (err < 0)
		throw std::runtime_error(armadillo::errmsg("dprintf"));
	delay = d;
}

int armadillo::accel::get_value(double *x, double *y, double *z)
{
	int rx, ry, rz;
	if (get_raw_value(&rx, &ry, &rz) == -1)
		return -1;

	*x = rx / SENSITIVITY;
	*y = ry / SENSITIVITY;
	*z = rz / SENSITIVITY;

	return 0;
}

int armadillo::accel::get_value(double *a)
{
	double x, y, z;
	if (get_value(&x, &y, &z) == -1)
		return -1;

	*a = std::sqrt(x * x + y * y + z * z);

	return 0;
}

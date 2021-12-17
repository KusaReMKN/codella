#include "touch.hh"

const char *const armadillo::touch::TOUCH_PATH = "/dev/input/event1";

void *armadillo::touch::handler_wrapper(void *arg)
{
	handler_arg_t *tmp = (handler_arg_t *)arg;
	touch_event_t ev = tmp->event;
	touch *self = tmp->self;
	(*self->handlers[ev.type])(ev, self->args[ev.type]);
	free(arg);
	return NULL;
}

void armadillo::touch::call_handler(handler_arg_t *arg)
{
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	int err;
	pthread_t ignore;
	do {
		err = pthread_create(&ignore, &attr, handler_wrapper, arg);
	} while (err == EAGAIN);
	if (err != 0)
		throw std::runtime_error(
			armadillo::errmsg("pthread_create", err));

	pthread_attr_destroy(&attr);
}

void *armadillo::touch::event_loop(void *me)
{
	touch *self = (touch *)me;

	int types[3][3][2] = {
		{
			{ TE_NONE,  TE_NONE  },
			{ TE_START, TE_NONE  },
			{ TE_START, TE_START }
		}, {
			{ TE_END,   TE_NONE  },
			{ TE_MOVE,  TE_NONE  },
			{ TE_MOVE,  TE_START },
		}, {
			{ TE_END,   TE_END   },
			{ TE_MOVE,  TE_END   },
			{ TE_MOVE,  TE_MOVE  },
		}
	};

	while (self->enabled) {
		self->update_frame();

		for (int i = 0; i < 2; i++) {
			int type = types[self->prev_touches][self->touches][i];
			if (self->handlers[type] == NULL)
				continue;

			handler_arg_t *arg;
			arg = (handler_arg_t *)malloc(sizeof(handler_arg_t));
			if (arg == NULL)
				throw std::runtime_error(
					armadillo::errmsg("malloc"));

			arg->self = self;
			arg->event.type = type;
			arg->event.touches = self->touches;
			arg->event.touch = i;
			arg->event.value = self->values[i];

			self->call_handler(arg);
		}
	}

	return NULL;
}

void armadillo::touch::update_frame()
{
	prev_touches = touches;
	touches = 0;

	bool sync = 0;
	bool key = 0;
	while (read_event(&sync, &key));
	if (touches == 0 && !key)
		touches = prev_touches;
}

int armadillo::touch::read_event(bool *sync, bool *key)
{
	fd_set rfs;
	FD_ZERO(&rfs);
	FD_SET(touch_file, &rfs);

	struct timeval timeout;
	timeout.tv_sec = 0;
	timeout.tv_usec = 10000;

	int err;
	err = select(touch_file + 1, &rfs, NULL, NULL, &timeout);
	if (err == -1)
		throw std::runtime_error(armadillo::errmsg("select"));
	else if (err == 0)
		return 0;

	struct input_event ev;
	err = read(touch_file, &ev, sizeof(ev));
	if (err == -1)
		throw std::runtime_error(armadillo::errmsg("read"));

	switch (ev.type) {
	case EV_ABS:
		switch (ev.code) {
		case ABS_MT_TOUCH_MAJOR:
			values[touches].p = ev.value;
			if (touches != 0)
				*sync = false;
			break;
		case ABS_MT_POSITION_X:
			values[touches].x = ev.value;
			break;
		case ABS_MT_POSITION_Y:
			values[touches].y = ev.value;
			touches++;
			break;
		case ABS_PRESSURE:
		case ABS_X:
		case ABS_Y:
			break;	// Ignore. I don't use these values.
		default:
			throw std::runtime_error(armadillo::errmsg(
					"read_event", "unknown code"));
		}
		break;
	case EV_SYN:
		if (*sync)
			return 0;
		*sync = true;
		break;
	case EV_KEY:
		*key = true;
		break;	// Ignore. I don't use this value.
	default:
		throw std::runtime_error(armadillo::errmsg("read_event",
					"unknown type"));
	}

	return 1;
}

armadillo::touch::touch()
{
	touch_file = open(TOUCH_PATH, O_RDONLY);
	if (touch_file == -1)
		throw std::runtime_error(armadillo::errmsg("open"));
	for (int i = 0; i < TE_MAX; i++) {
		handlers[i] = NULL;
		args[i] = NULL;
	}
}

armadillo::touch::~touch()
{
	close(touch_file);
}

void armadillo::touch::enable()
{
	enabled = true;
	prev_touches = touches = 0;
	std::memset(values, 0, sizeof(values));
	int err;
	err = pthread_create(&event_thread, NULL, event_loop, this);
	if (err != 0)
		throw std::runtime_error(
			armadillo::errmsg("pthread_create", err));
}

void armadillo::touch::disable()
{
	enabled = false;
	int err;
	err = pthread_join(event_thread, NULL);
	if (err != 0)
		throw std::runtime_error(
			armadillo::errmsg("pthread_join", err));
}

void armadillo::touch::on_none(void (*handler)(touch_event_t, void *),
		void *arg)
{
	handlers[TE_NONE] = handler;
	args[TE_NONE] = arg;
}

void armadillo::touch::on_start(void (*handler)(touch_event_t, void *),
		void *arg)
{
	handlers[TE_START] = handler;
	args[TE_START] = arg;
}

void armadillo::touch::on_move(void (*handler)(touch_event_t, void *),
		void *arg)
{
	handlers[TE_MOVE] = handler;
	args[TE_MOVE] = arg;
}

void armadillo::touch::on_end(void (*handler)(touch_event_t, void *),
		void *arg)
{
	handlers[TE_END] = handler;
	args[TE_END] = arg;
}

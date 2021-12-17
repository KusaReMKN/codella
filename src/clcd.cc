#include "clcd.hh"

const char *const armadillo::clcd::CLCD_PATH = "/dev/hd44780";

armadillo::clcd::clcd()
{
	clcd_file = open(CLCD_PATH, O_WRONLY);
	if (clcd_file == -1)
		throw std::runtime_error(armadillo::errmsg("open"));
}

armadillo::clcd::~clcd()
{
	close(clcd_file);
}

int armadillo::clcd::putc(int c)
{
	char d;
	d = c & 0xFF;
	int err;
	err = write(clcd_file, &d, 1);
	if (err == -1)
		throw std::runtime_error(armadillo::errmsg("write"));
	return d;
}



int armadillo::clcd::printf(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int ret;
	ret = vdprintf(clcd_file, fmt, ap);
	va_end(ap);
	if (ret < 0)
		throw std::runtime_error(armadillo::errmsg("vdprintf"));
	return ret;
}

void armadillo::clcd::puts(const char *str)
{
	int err;
	err = write(clcd_file, str, strlen(str));
	if (err == -1)
		throw std::runtime_error(armadillo::errmsg("write"));
}

void armadillo::clcd::puts(std::string str)
{
	return puts(str.c_str());
}

int armadillo::clcd::clear()
{
	return putc('\f');
}

int armadillo::clcd::curpos(int r, int c)
{
	return printf("\x1b[%d;%dH", r, c);
}

int armadillo::clcd::reset()
{
	return curpos(1, 1);
}

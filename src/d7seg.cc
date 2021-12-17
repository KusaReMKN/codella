#include "d7seg.hh"

const char *const armadillo::d7seg::D7SEG_PATH = "/dev/d7seg";

armadillo::d7seg::d7seg()
{
	d7seg_file = open(D7SEG_PATH, O_WRONLY);
	if (d7seg_file == -1)
		throw std::runtime_error(armadillo::errmsg("open"));
}

armadillo::d7seg::~d7seg()
{
	close(d7seg_file);
}

void armadillo::d7seg::set_decimal(int n)
{
	unsigned char d;
	d = n % 100;
	d = (((d / 10) << 4) | (d % 10));

	int err;
	err = write(d7seg_file, &d, 1);
	if (err == -1)
		throw std::runtime_error(armadillo::errmsg("write"));
}

void armadillo::d7seg::set_hexadecimal(int n)
{
	unsigned char d;
	d = n & 0xFF;

	int err;
	err = write(d7seg_file, &d, 1);
	if (err == -1)
		throw std::runtime_error(armadillo::errmsg("write"));
}

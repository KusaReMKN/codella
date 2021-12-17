#pragma once
#ifndef CODELLA_D7SEG_HH
#define CODELLA_D7SEG_HH

#ifndef __cplusplus
#error C++ Required.
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdexcept>

#include "armadillo.hh"

namespace armadillo {
	class d7seg {
		static const char *const D7SEG_PATH;
	
		int d7seg_file;
	public:
		d7seg();
		~d7seg();
		void set_decimal(int n);
		void set_hexadecimal(int n);
	};
};

#endif // CODELLA_D7SEG_HH


#pragma once
#ifndef CODELLA_CLCD_HH
#define CODELLA_CLCD_HH

#ifndef __cplusplus
#error C++ Required.
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <cstdio>
#include <cstdarg>
#include <cstring>

#include <string>
#include <stdexcept>

#include "armadillo.hh"

namespace armadillo {
	class clcd {
		static const char *const CLCD_PATH;

		int clcd_file;
	public:
		clcd();
		~clcd();
		int putc(int c);
		int printf(const char *fmt, ...);
		void puts(const char *str);
		void puts(std::string str);
		int clear();
		int curpos(int r, int c);
		int reset();
	};
};

#endif // CODELLA_CLCD_HH

#pragma once
#ifndef CODELLA_ACCEL_HH
#define CODELLA_ACCEL_HH

#ifndef __cplusplus
#error C++ Required.
#endif

#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#include <cstdio>
#include <cmath>

#include <stdexcept>

#include "armadillo.hh"

namespace armadillo {
	class accel {
		static const char *const DELAY_PATH;
		static const char *const ENABLE_PATH;
		static const char *const EVENT_PATH;
		enum {
			NONE = 00,
			X_READ = 01,
			Y_READ = 02,
			Z_READ = 04,
			ALL_READ = 07,
		};
		static double const SENSITIVITY;

		int delay_file;
		int enable_file;
		int event_file;

		bool enabled;
		unsigned int delay;
		pthread_mutex_t value_mutex;
		pthread_t event_thread;
		struct { int x, y, z; } temp, value;
		int read_flag;

		static void *event_loop(void *me);
		void set_sensor(bool on);
		void read_event();

		int get_raw_value(int *x, int *y, int *z);
	public:
		accel();
		~accel();
		void enable();
		void disable();
		void set_delay(unsigned int d);

		int get_value(double *x, double *y, double *z);
		int get_value(double *a);
	};
};

#endif // CODELLA_ACCEL_HH

#pragma once
#ifndef CODELLA_TOUCH_HH
#define CODELLA_TOUCH_HH

#include <linux/input.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#include <cstring>
#include <stdexcept>

#include "armadillo.hh"

namespace armadillo {
	class touch {
	public:
		enum { TE_NONE, TE_START, TE_MOVE, TE_END, TE_MAX };
		typedef struct { int p, x, y; } touch_point_t;
		typedef struct {
			int type;
			int touches;
			int touch;
			touch_point_t value;
		} touch_event_t;
	private:
		static const char *const TOUCH_PATH;

		int touch_file;

		bool enabled;
		pthread_t event_thread;
		int touches, prev_touches;
		touch_point_t values[2];
		void (*handlers[TE_MAX])(touch_event_t, void *);
		void *args[TE_MAX];

		typedef struct {
			touch *self;
			touch_event_t event;
		} handler_arg_t;
		static void *handler_wrapper(void *arg);
		void call_handler(handler_arg_t *ev);
		static void *event_loop(void *me);
		void update_frame();
		int read_event(bool *sync, bool *key);
	public:
		touch();
		~touch();

		void enable();
		void disable();

		void on_none(void (*handler)(touch_event_t, void *),
				void *arg = NULL);
		void on_start(void (*handler)(touch_event_t, void *),
				void *arg = NULL);
		void on_move(void (*handler)(touch_event_t, void *),
				void *arg = NULL);
		void on_end(void (*handler)(touch_event_t, void *),
				void *arg = NULL);
	};
};

#endif // CODELLA_TOUCH_HH

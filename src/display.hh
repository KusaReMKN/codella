#ifndef CODELLA_DISPLAY_HH
#define CODELLA_DISPLAY_HH

#ifndef __cplusplus
#error C++ Required.
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>

#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cwchar>
#include <clocale>
#include <cmath>
#include <cstring>
#include <csetjmp>
#include <map>
#include <stdexcept>

#include "armadillo.hh"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <jpeglib.h>

namespace armadillo {
	class display {
	public:
		class color {
		public:
			typedef struct {
				uint8_t b;
				uint8_t g;
				uint8_t r;
				uint8_t a;
			} __attribute__((__packed__)) color_t;
		private:
			static const std::map<std::string, color_t> color_name;
			color_t value;
		public:
			color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0);
			color(color_t c);
			color(std::string name);
			color_t get_color();
		};

	private:
		static const char *const DISPLAY_PATH;
		static int const BYTES_PER_PIXEL;
		static int const DISPLAY_PIXELS;
		static int const DISPLAY_BUFFER_SIZE;

		int display_file;
		color::color_t *display_buf;
		color::color_t *worker_buf;
		unsigned int draw_level;
		pthread_mutex_t draw_mutex;

		FT_Library library;
		struct { FT_Face face; bool set; } face_set;
		static const char *ftstrerror(FT_Error error);
		void draw_char(int x, int y, wchar_t ch, color c, int *d,
				bool v);

		int pixel_index(int x, int y);

		typedef struct {
			unsigned int width, height;
			unsigned int ch;
			uint8_t *bitmap;
		} bitmap_t;
		void draw_bitmap(int x, int y, int w, int h, bitmap_t bmp);
	public:
		static int const DISPLAY_WIDTH;
		static int const DISPLAY_HEIGHT;

		display();
		~display();

		void draw_start();
		void draw_init();
		void draw_end();

		void clear();
		void fill(color c);
		void dot(int x, int y, color c);
		void dot_alpha(int x, int y, color c);
		void line(int x1, int y1, int x2, int y2, color c);
		void rect(int x, int y, int w, int h, color c, bool f = 0);
		void ellipse(int x, int y, int a, int b, color c, bool f = 0);
		void circle(int x, int y, int r, color c, bool f = 0);

		void text_font(const char *path);
		void text_size(unsigned int px);
		void text(int x, int y, const char *s, color c, bool v = 0);
		void printf(int x, int y, color c, bool v, const char *f, ...);

		void draw_jpeg(int x, int y, int w, int h, const char *path);
		void draw_jpeg(int x, int y, int w, int h,
				unsigned char *data, unsigned long len);
	};
};

#endif // CODELLA_DISPLAY_HH

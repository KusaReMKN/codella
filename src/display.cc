#include "display.hh"

const std::map<std::string, armadillo::display::color::color_t>
armadillo::display::color::color_name = {
	{ "black",		{ 0x00, 0x00, 0x00, } },
	{ "silver",		{ 0xC0, 0xC0, 0xC0, } },
	{ "gray",		{ 0x80, 0x80, 0x80, } },
	{ "white",		{ 0xFF, 0xFF, 0xFF, } },
	{ "maroon",		{ 0x00, 0x00, 0x80, } },
	{ "red",		{ 0x00, 0x00, 0xFF, } },
	{ "purple",		{ 0x80, 0x00, 0x80, } },
	{ "fuchsia",		{ 0xFF, 0x00, 0xFF, } },
	{ "green",		{ 0x00, 0x80, 0x00, } },
	{ "lime",		{ 0x00, 0xFF, 0x00, } },
	{ "olive",		{ 0x00, 0x80, 0x80, } },
	{ "yellow",		{ 0x00, 0xFF, 0xFF, } },
	{ "navy",		{ 0x80, 0x00, 0x00, } },
	{ "blue",		{ 0xFF, 0x00, 0x00, } },
	{ "teal",		{ 0x80, 0x80, 0x00, } },
	{ "aqua",		{ 0xFF, 0xFF, 0x00, } },

	{ "orange",		{ 0x00, 0xA5, 0xFF, } },

	{ "aliceblue",		{ 0xFF, 0xF8, 0xF0, } },
	{ "antiquewhite",	{ 0xD7, 0xEB, 0xFA, } },
	{ "aquamarine",		{ 0xD4, 0xFF, 0x7F, } },
	{ "azure",		{ 0xFF, 0xFF, 0xF0, } },
	{ "beige",		{ 0xDC, 0xF5, 0xF5, } },
	{ "bisque",		{ 0xC4, 0xE4, 0xFF, } },
	{ "blanchedalmond",	{ 0xCD, 0xEB, 0xFF, } },
	{ "blueviolet",		{ 0xE2, 0x2B, 0x8A, } },
	{ "brown",		{ 0x2A, 0x2A, 0xA5, } },
	{ "burlywood",		{ 0x87, 0xB8, 0xDE, } },
	{ "cadetblue",		{ 0xA0, 0x9E, 0x5F, } },
	{ "chartreuse",		{ 0x00, 0xFF, 0x7F, } },
	{ "chocolate",		{ 0x1E, 0x69, 0xD2, } },
	{ "coral",		{ 0x50, 0x7F, 0xFF, } },
	{ "cornflowerblue",	{ 0xED, 0x95, 0x64, } },
	{ "cornsilk",		{ 0xDC, 0xF8, 0xFF, } },
	{ "crimson",		{ 0x3C, 0x14, 0xDC, } },
	{ "cyan",		{ 0xFF, 0xFF, 0x00, } },
	{ "darkblue",		{ 0x8B, 0x00, 0x00, } },
	{ "darkcyan",		{ 0x8B, 0x8B, 0x00, } },
	{ "darkgoldenrod",	{ 0x0B, 0x86, 0xB8, } },
	{ "darkgray",		{ 0xA9, 0xA9, 0xA9, } },
	{ "darkgreen",		{ 0x00, 0x64, 0x00, } },
	{ "darkgrey",		{ 0xA9, 0xA9, 0xA9, } },
	{ "darkkhaki",		{ 0x6B, 0xB7, 0xBD, } },
	{ "darkmagenta",	{ 0x8B, 0x00, 0x8B, } },
	{ "darkolivegreen",	{ 0x2F, 0x6B, 0x55, } },
	{ "darkorange",		{ 0x00, 0x8C, 0xFF, } },
	{ "darkorchid",		{ 0xCC, 0x32, 0x99, } },
	{ "darkred",		{ 0x00, 0x00, 0x8B, } },
	{ "darksalmon",		{ 0x7A, 0x96, 0xE9, } },
	{ "darkseagreen",	{ 0x8F, 0xBC, 0x8F, } },
	{ "darkslateblue",	{ 0x8B, 0x3D, 0x48, } },
	{ "darkslategray",	{ 0x4F, 0x4F, 0x2F, } },
	{ "darkslategrey",	{ 0x4F, 0x4F, 0x2F, } },
	{ "darkturquoise",	{ 0xD1, 0xCE, 0x00, } },
	{ "darkviolet",		{ 0xD3, 0x00, 0x94, } },
	{ "deeppink",		{ 0x93, 0x14, 0xFF, } },
	{ "deepskyblue",	{ 0xFF, 0xBF, 0x00, } },
	{ "dimgray",		{ 0x69, 0x69, 0x69, } },
	{ "dimgrey",		{ 0x69, 0x69, 0x69, } },
	{ "dodgerblue",		{ 0xFF, 0x90, 0x1E, } },
	{ "firebrick",		{ 0x22, 0x22, 0xB2, } },
	{ "floralwhite",	{ 0xF0, 0xFA, 0xFF, } },
	{ "forestgreen",	{ 0x22, 0x8B, 0x22, } },
	{ "gainsboro",		{ 0xDC, 0xDC, 0xDC, } },
	{ "ghostwhite",		{ 0xFF, 0xF8, 0xF8, } },
	{ "gold",		{ 0x00, 0xD7, 0xFF, } },
	{ "goldenrod",		{ 0x20, 0xA5, 0xDA, } },
	{ "greenyellow",	{ 0x2F, 0xFF, 0xAD, } },
	{ "grey",		{ 0x80, 0x80, 0x80, } },
	{ "honeydew",		{ 0xF0, 0xFF, 0xF0, } },
	{ "hotpink",		{ 0xB4, 0x69, 0xFF, } },
	{ "indianred",		{ 0x5C, 0x5C, 0xCD, } },
	{ "indigo",		{ 0x82, 0x00, 0x4B, } },
	{ "ivory",		{ 0xF0, 0xFF, 0xFF, } },
	{ "khaki",		{ 0x8C, 0xE6, 0xF0, } },
	{ "lavender",		{ 0xFA, 0xE6, 0xE6, } },
	{ "lavenderblush",	{ 0xF5, 0xF0, 0xFF, } },
	{ "lawngreen",		{ 0x00, 0xFC, 0x7C, } },
	{ "lemonchiffon",	{ 0xCD, 0xFA, 0xFF, } },
	{ "lightblue",		{ 0xE6, 0xD8, 0xAD, } },
	{ "lightcoral",		{ 0x80, 0x80, 0xF0, } },
	{ "lightcyan",		{ 0xFF, 0xFF, 0xE0, } },
	{ "lightgoldenrodyellow",	{ 0xD2, 0xFA, 0xFA, } },
	{ "lightgray",		{ 0xD3, 0xD3, 0xD3, } },
	{ "lightgreen",		{ 0x90, 0xEE, 0x90, } },
	{ "lightgrey",		{ 0xD3, 0xD3, 0xD3, } },
	{ "lightpink",		{ 0xC1, 0xB6, 0xFF, } },
	{ "lightsalmon",	{ 0x7A, 0xA0, 0xFF, } },
	{ "lightseagreen",	{ 0xAA, 0xB2, 0x20, } },
	{ "lightskyblue",	{ 0xFA, 0xCE, 0x87, } },
	{ "lightslategray",	{ 0x99, 0x88, 0x77, } },
	{ "lightslategrey",	{ 0x99, 0x88, 0x77, } },
	{ "lightsteelblue",	{ 0xDE, 0xC4, 0xB0, } },
	{ "lightyellow",	{ 0xE0, 0xFF, 0xFF, } },
	{ "limegreen",		{ 0x32, 0xCD, 0x32, } },
	{ "linen",		{ 0xE6, 0xF0, 0xFA, } },
	{ "magenta",		{ 0xFF, 0x00, 0xFF, } },
	{ "mediumaquamarine",	{ 0xAA, 0xCD, 0x66, } },
	{ "mediumblue",		{ 0xCD, 0x00, 0x00, } },
	{ "mediumorchid",	{ 0xD3, 0x55, 0xBA, } },
	{ "mediumpurple",	{ 0xDB, 0x70, 0x93, } },
	{ "mediumseagreen",	{ 0x71, 0xB3, 0x3C, } },
	{ "mediumslateblue",	{ 0xEE, 0x68, 0x7B, } },
	{ "mediumspringgreen",	{ 0x9A, 0xFA, 0x00, } },
	{ "mediumturquoise",	{ 0xCC, 0xD1, 0x48, } },
	{ "mediumvioletred",	{ 0x85, 0x15, 0xC7, } },
	{ "midnightblue",	{ 0x70, 0x19, 0x19, } },
	{ "mintcream",		{ 0xFA, 0xFF, 0xF5, } },
	{ "mistyrose",		{ 0xE1, 0xE4, 0xFF, } },
	{ "moccasin",		{ 0xB5, 0xE4, 0xFF, } },
	{ "navajowhite",	{ 0xAD, 0xDE, 0xFF, } },
	{ "oldlace",		{ 0xE6, 0xF5, 0xFD, } },
	{ "olivedrab",		{ 0x23, 0x8E, 0x6B, } },
	{ "orangered",		{ 0x00, 0x45, 0xFF, } },
	{ "orchid",		{ 0xD6, 0x70, 0xDA, } },
	{ "palegoldenrod",	{ 0xAA, 0xE8, 0xEE, } },
	{ "palegreen",		{ 0x98, 0xFB, 0x98, } },
	{ "paleturquoise",	{ 0xEE, 0xEE, 0xAF, } },
	{ "palevioletred",	{ 0x93, 0x70, 0xDB, } },
	{ "papayawhip",		{ 0xD5, 0xEF, 0xFF, } },
	{ "peachpuff",		{ 0xB9, 0xDA, 0xFF, } },
	{ "peru",		{ 0x3F, 0x85, 0xCD, } },
	{ "pink",		{ 0xCB, 0xC0, 0xFF, } },
	{ "plum",		{ 0xDD, 0xA0, 0xDD, } },
	{ "powderblue",		{ 0xE6, 0xE0, 0xB0, } },
	{ "rosybrown",		{ 0x8F, 0x8F, 0xBC, } },
	{ "royalblue",		{ 0xE1, 0x69, 0x41, } },
	{ "saddlebrown",	{ 0x13, 0x45, 0x8B, } },
	{ "salmon",		{ 0x72, 0x80, 0xFA, } },
	{ "sandybrown",		{ 0x60, 0xA4, 0xF4, } },
	{ "seagreen",		{ 0x57, 0x8B, 0x2E, } },
	{ "seashell",		{ 0xEE, 0xF5, 0xFF, } },
	{ "sienna",		{ 0x2D, 0x52, 0xA0, } },
	{ "skyblue",		{ 0xEB, 0xCE, 0x87, } },
	{ "slateblue",		{ 0xCD, 0x5A, 0x6A, } },
	{ "slategray",		{ 0x90, 0x80, 0x70, } },
	{ "slategrey",		{ 0x90, 0x80, 0x70, } },
	{ "snow",		{ 0xFA, 0xFA, 0xFF, } },
	{ "springgreen",	{ 0x7F, 0xFF, 0x00, } },
	{ "steelblue",		{ 0xB4, 0x82, 0x46, } },
	{ "tan",		{ 0x8C, 0xB4, 0xD2, } },
	{ "thistle",		{ 0xD8, 0xBF, 0xD8, } },
	{ "tomato",		{ 0x47, 0x63, 0xFF, } },
	{ "turquoise",		{ 0xD0, 0xE0, 0x40, } },
	{ "violet",		{ 0xEE, 0x82, 0xEE, } },
	{ "wheat",		{ 0xB3, 0xDE, 0xF5, } },
	{ "whitesmoke",		{ 0xF5, 0xF5, 0xF5, } },
	{ "yellowgreen",	{ 0x32, 0xCD, 0x9A, } },

	{ "rebeccapurple",	{ 0x99, 0x33, 0x66, } },

	{ "KusaReMKN",		{ 0x00, 0x7F, 0xFF, } },
};

armadillo::display::color::color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	color_t temp = { b, g, r, a };
	value = temp;
}

armadillo::display::color::color(color_t c)
{
	value = c;
}

armadillo::display::color::color(std::string name)
{
	if (name[0] == '#' && name.length() == 7) {
		value.r = std::stoi(name.substr(1, 2), nullptr, 16);
		value.g = std::stoi(name.substr(3, 2), nullptr, 16);
		value.b = std::stoi(name.substr(5, 2), nullptr, 16);
		value.a = 0;
	} else if (name[0] == '#' && name.length() == 4) {
		value.r = std::stoi(name.substr(1, 1), nullptr, 16) * 0x11;
		value.g = std::stoi(name.substr(2, 1), nullptr, 16) * 0x11;
		value.b = std::stoi(name.substr(3, 1), nullptr, 16) * 0x11;
		value.a = 0;
	} else {
		value = color_name.at(name);
	}
}

armadillo::display::color::color_t
armadillo::display::color::get_color()
{
	return value;
}

const char *const
armadillo::display::DISPLAY_PATH = "/dev/fb0";
int const
armadillo::display::DISPLAY_WIDTH = 800;
int const
armadillo::display::DISPLAY_HEIGHT = 480;
int const
armadillo::display::BYTES_PER_PIXEL = 4;
int const
armadillo::display::DISPLAY_PIXELS =
	armadillo::display::DISPLAY_WIDTH *
	armadillo::display::DISPLAY_HEIGHT;
int const
armadillo::display::DISPLAY_BUFFER_SIZE =
	armadillo::display::BYTES_PER_PIXEL *
	armadillo::display::DISPLAY_PIXELS;

const char *
armadillo::display::ftstrerror(FT_Error error)
{
#undef FTERRORS_H_
#define FT_ERRORDEF(error_code, value, string) case error_code: return string;
#define FT_ERROR_START_LIST switch(error) {
#define FT_ERROR_END_LIST default: return "Unknown error"; }
#include FT_ERRORS_H
}

armadillo::display::display():
	draw_level(0)
{
	display_file = open(DISPLAY_PATH, O_RDWR);
	if (display_file == -1)
		throw std::runtime_error(armadillo::errmsg("open"));

	display_buf = (color::color_t *)mmap(NULL, DISPLAY_BUFFER_SIZE,
			PROT_READ | PROT_WRITE, MAP_SHARED, display_file, 0);
	if (display_buf == MAP_FAILED)
		throw std::runtime_error(armadillo::errmsg("mmap(display)"));

	worker_buf = (color::color_t *)mmap(NULL, DISPLAY_BUFFER_SIZE,
			PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
			-1, 0);
	if (worker_buf == MAP_FAILED)
		throw std::runtime_error(armadillo::errmsg("mmap(worker)"));

	int err = FT_Init_FreeType(&library);
	if (err != 0)
		throw std::runtime_error(armadillo::errmsg("FT_Init_FreeType",
					ftstrerror(err)));
	face_set.set = false;

	if (std::setlocale(LC_CTYPE, "") == NULL)
		throw std::runtime_error(armadillo::errmsg("setlocale"));
}

armadillo::display::~display()
{
	// TODO: locale (if need)

	if (face_set.set)
		FT_Done_Face(face_set.face);
	FT_Done_FreeType(library);

	munmap(worker_buf, DISPLAY_BUFFER_SIZE);
	munmap(display_buf, DISPLAY_BUFFER_SIZE);
	close(display_file);
}

void
armadillo::display::draw_start()
{
	if (draw_level++ == 0)
		std::memcpy(worker_buf, display_buf, DISPLAY_BUFFER_SIZE);
}

void
armadillo::display::draw_init()
{
	if (draw_level++ == 0)
		std::memset(worker_buf, 0, DISPLAY_BUFFER_SIZE);
}

void
armadillo::display::draw_end()
{
	if (--draw_level == 0)
		std::memcpy(display_buf, worker_buf, DISPLAY_BUFFER_SIZE);
}

int
armadillo::display::pixel_index(int x, int y)
{
	if (x < 0 || x >= DISPLAY_WIDTH || y < 0 || y >= DISPLAY_HEIGHT)
		return -1;
	return x + DISPLAY_WIDTH * y;
}

void
armadillo::display::clear()
{
	std::memset(display_buf, 0, DISPLAY_BUFFER_SIZE);
}

void
armadillo::display::fill(color c)
{
	draw_start();
	for (int i = 0; i < DISPLAY_PIXELS; i++)
		worker_buf[i] = c.get_color();
	draw_end();
}

void
armadillo::display::dot(int x, int y, color c)
{
	int index;
	index = pixel_index(x, y);
	if (index == -1)
		return;		// out of display

	draw_start();
	worker_buf[index] = c.get_color();
	draw_end();
}

void
armadillo::display::dot_alpha(int x, int y, color c)
{
	int index;
	index = pixel_index(x, y);
	if (index == -1)
		return;		// out of display

	color::color_t tmp, dest;
	tmp = c.get_color();
	dest = worker_buf[index];

	tmp.r = ((int)tmp.r - dest.r) * tmp.a / 0x100 + dest.r;
	tmp.g = ((int)tmp.g - dest.g) * tmp.a / 0x100 + dest.g;
	tmp.b = ((int)tmp.b - dest.b) * tmp.a / 0x100 + dest.b;

	draw_start();
	worker_buf[index] = tmp;
	draw_end();
}

void
armadillo::display::line(int x1, int y1, int x2, int y2, color c)
{
	int x, y;
	x = x2 - x1;
	y = y2 - y1;

	double dt;
	dt = 1 / (std::sqrt(x * x + y * y) + 1);

	draw_start();
	for (double t = 0; t < 1; t += dt)
		dot(x1 + x * t, y1 + y * t, c);
	draw_end();
}

void
armadillo::display::rect(int x, int y, int w, int h, color c, bool f)
{
	int p, q;
	p = x + w - 1;
	q = y + h - 1;

	draw_start();
	line(x, y, p, y, c);
	line(x, y, x, q, c);
	line(p, y, p, q, c);
	line(x, q, p, q, c);
	dot(p, q, c);
	for (int i = 0; f && i < h; i++)
		line(x, y + i, p, y + i, c);
	draw_end();
}

void
armadillo::display::ellipse(int x, int y, int a, int b, color c, bool f)
{
	const double pi  = 4 * std::atan(1);
	const double pi2 = 2 * pi;

	double dt;
	dt = 1 / ((a > b ? a : b) * pi2);

	draw_start();
	if (f) {
		for (double t = 0; t < .5; t += dt) {
			double th, dx, dy, dw, dh;
			th = t * pi + pi;
			dx = x + a * std::cos(th);
			dy = y + b * std::sin(th);
			dw = 2 * std::fabs(a * std::cos(th));
			dh = 2 * std::fabs(b * std::sin(th));
			rect(dx, dy, dw, dh, c, false);
		}
	} else {
		for (double t = 0; t < 1; t += dt) {
			double th, dx, dy;
			th = t * pi2;
			dx = x + a * std::cos(th);
			dy = y + b * std::sin(th);
			dot(dx, dy, c);
		}
	}
	draw_end();
}

void
armadillo::display::circle(int x, int y, int r, color c, bool f)
{
	ellipse(x, y, r, r, c, f);
}

void
armadillo::display::text_font(const char *path)
{
	if (face_set.set)
		FT_Done_Face(face_set.face);

	int err;
	err = FT_New_Face(library, path, 0, &face_set.face);
	if (err != 0)
		throw std::runtime_error(armadillo::errmsg("FT_New_Face",
				ftstrerror(err)));
	face_set.set = true;
}

void
armadillo::display::text_size(unsigned int px)
{
	if (!face_set.set)
		return;

	int err;
	err = FT_Set_Pixel_Sizes(face_set.face, 0, px);
	if (err != 0)
		throw std::runtime_error(armadillo::errmsg(
				"FT_Set_Pixel_Sizes", ftstrerror(err)));
}

void
armadillo::display::draw_char(int x, int y, wchar_t ch, color c, int *d,
		bool v)
{
	int err;
	err = FT_Load_Char(face_set.face, ch,
			FT_LOAD_RENDER | (v ? FT_LOAD_VERTICAL_LAYOUT : 0));
	if (err != 0)
		throw std::runtime_error(armadillo::errmsg("FT_Load_Char",
				ftstrerror(err)));

	FT_GlyphSlot slot = face_set.face->glyph;
	FT_Size size = face_set.face->size;
	FT_Bitmap bmp = slot->bitmap;
	draw_start();
	for (unsigned int i = 0; i < bmp.rows * bmp.width; i++) {
		int cx, cy;
		cx = i % bmp.width + x + slot->bitmap_left;
		cy = i / bmp.width + y - slot->bitmap_top +
			(size->metrics.descender >> 6);
		if (bmp.buffer[i] == 0xFF) {
			dot(cx, cy, c);
		} else if (bmp.buffer[i] == 0x00) {
			; // No thing to do
		} else {
			color::color_t tmp = c.get_color();
			tmp.a = bmp.buffer[i];
			dot_alpha(cx, cy, color(tmp));
		}
	}
	draw_end();

	if (d) {
		d[0] = slot->advance.x >> 6;
		d[1] = slot->advance.y >> 6;
	}
}

void
armadillo::display::text(int x, int y, const char *s, color c, bool v)
{
	int err;
	wchar_t buf[1024];
	err = mbstowcs(buf, s, sizeof(buf) / sizeof(buf[0]));
	if (err == -1)
		throw std::runtime_error(armadillo::errmsg("mbstowcs"));

	draw_start();
	for (int i = 0; buf[i]; i++) {
		int d[2];
		draw_char(x, y, buf[i], c, d, v);
		x += d[0];
		y += d[1];
	}
	draw_end();
}

void
armadillo::display::printf(int x, int y, color c, bool v, const char *f, ...)
{
	va_list ap;
	va_start(ap, f);

	int err;
	char buf[4096];
	err = vsnprintf(buf, sizeof(buf), f, ap);
	if (err < 0)
		throw std::runtime_error(armadillo::errmsg("vsnprintf"));

	va_end(ap);

	text(x, y, buf, c, v);
}

void
armadillo::display::draw_bitmap(int x, int y, int w, int h, bitmap_t bmp)
{
	int rw, rh;
	if (w == -1 && h == -1)
		rw = bmp.width, rh = bmp.height;
	else if (h == -1)
		rw = w, rh = bmp.height * w / bmp.width;
	else if (w == -1)
		rw = bmp.width * h / bmp.height, rh = h;
	else
		rw = w, rh = h;

	draw_start();
	for (int i = 0; i < rh; i++) {
		for (int j = 0; j < rw; j++) {
			int rx, ry;
			rx = j * bmp.width / rw;
			ry = i * bmp.height / rh;
			int index;
			index = bmp.ch * (rx + bmp.width * ry);

			switch (bmp.ch) {
			case 1: {
				int c;
				c = bmp.bitmap[index];
				dot(x + j, y + i, color(c, c, c));
			}	break;
			case 3: {
				int r, g, b;
				r = bmp.bitmap[index + 0];
				g = bmp.bitmap[index + 1];
				b = bmp.bitmap[index + 2];
				dot(x + j, y + i, color(r, g, b));
			}	break;
			case 4: {
				int r, g, b, a;
				r = bmp.bitmap[index + 0];
				g = bmp.bitmap[index + 1];
				b = bmp.bitmap[index + 2];
				a = bmp.bitmap[index + 3];
				dot_alpha(x + j, y + i, color(r, g, b, a));
			}	break;
			default:
				;	// What can I do?
			}
		}
	}
	draw_end();
}

void
armadillo::display::draw_jpeg(int x, int y, int w, int h, const char *path)
{
	struct error_mgr {
		struct jpeg_error_mgr pub;
		char errmsg[JMSG_LENGTH_MAX];
		std::jmp_buf jmpbuf;
	};

	std::FILE *fp;
	fp = std::fopen(path, "rb");
	if (fp == NULL)
		throw std::runtime_error(armadillo::errmsg("fopen"));

	struct jpeg_decompress_struct jpeg;
	jpeg_create_decompress(&jpeg);

	struct error_mgr jerr;
	jpeg.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = [](j_common_ptr cinfo) {
		struct error_mgr *err;
		err = (struct error_mgr *)cinfo->err;
		cinfo->err->format_message(cinfo, err->errmsg);
		longjmp(err->jmpbuf, cinfo->err->msg_code);
	};

	int err;
	err = setjmp(jerr.jmpbuf);
	if (err != 0)
		throw std::runtime_error(armadillo::errmsg("draw_jpeg",
				jerr.errmsg));

	jpeg_stdio_src(&jpeg, fp);
	jpeg_read_header(&jpeg, TRUE);
	jpeg_start_decompress(&jpeg);

	bitmap_t bitmap;
	bitmap.ch = jpeg.out_color_components;
	bitmap.width = jpeg.output_width;
	bitmap.height = jpeg.output_height;

	size_t size;
	size = bitmap.ch * bitmap.width * bitmap.height;
	bitmap.bitmap = (uint8_t *)std::malloc(size);
	if (bitmap.bitmap == NULL)
		throw std::runtime_error(armadillo::errmsg("malloc"));

	for (unsigned int i = 0; i < jpeg.output_height; i++) {
		uint8_t *tmp;
		tmp = bitmap.bitmap + bitmap.ch * bitmap.width * i;
		jpeg_read_scanlines(&jpeg, &tmp, 1);
	}

	draw_bitmap(x, y, w, h, bitmap);
	free(bitmap.bitmap);

	jpeg_finish_decompress(&jpeg);
	jpeg_destroy_decompress(&jpeg);

	fclose(fp);
}

void
armadillo::display::draw_jpeg(int x, int y, int w, int h, unsigned char *data,
		unsigned long len)
{
	struct error_mgr {
		struct jpeg_error_mgr pub;
		char errmsg[JMSG_LENGTH_MAX];
		std::jmp_buf jmpbuf;
	};

	struct jpeg_decompress_struct jpeg;
	jpeg_create_decompress(&jpeg);

	struct error_mgr jerr;
	jpeg.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = [](j_common_ptr cinfo) {
		struct error_mgr *err;
		err = (struct error_mgr *)cinfo->err;
		cinfo->err->format_message(cinfo, err->errmsg);
		longjmp(err->jmpbuf, cinfo->err->msg_code);
	};

	int err;
	err = setjmp(jerr.jmpbuf);
	if (err != 0)
		throw std::runtime_error(armadillo::errmsg("draw_jpeg",
				jerr.errmsg));

	jpeg_mem_src(&jpeg, data, len);
	jpeg_read_header(&jpeg, TRUE);
	jpeg_start_decompress(&jpeg);

	bitmap_t bitmap;
	bitmap.ch = jpeg.out_color_components;
	bitmap.width = jpeg.output_width;
	bitmap.height = jpeg.output_height;

	size_t size;
	size = bitmap.ch * bitmap.width * bitmap.height;
	bitmap.bitmap = (uint8_t *)std::malloc(size);
	if (bitmap.bitmap == NULL)
		throw std::runtime_error(armadillo::errmsg("malloc"));

	for (unsigned int i = 0; i < jpeg.output_height; i++) {
		uint8_t *tmp;
		tmp = bitmap.bitmap + bitmap.ch * bitmap.width * i;
		jpeg_read_scanlines(&jpeg, &tmp, 1);
	}

	draw_bitmap(x, y, w, h, bitmap);
	free(bitmap.bitmap);

	jpeg_finish_decompress(&jpeg);
	jpeg_destroy_decompress(&jpeg);
}

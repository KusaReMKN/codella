#pragma once
#ifndef CODELLA_ARMADILLO_HH
#define CODELLA_ARMADILLO_HH

#ifndef __cplusplus
#error C++ Required.
#endif

#undef _GNU_SOURCE
#include <cstring>
#include <cerrno>
#include <string>
#include <sstream>

namespace armadillo {
	std::string errmsg(std::string s, int err = errno);
	std::string errmsg(std::string s, std::string d);
};

#endif // CODELLA_ARMADILLO_HH

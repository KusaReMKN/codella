#include "armadillo.hh"

extern char *__progname;	// Program name, from crt0.

std::string armadillo::errmsg(std::string s, int err)
{
	char errbuf[1024] = { 0 };
	strerror_r(err, errbuf, sizeof(errbuf));
	std::stringstream ss;
	ss << __progname << ": " << s << ": " << errbuf << std::endl;
	return ss.str();
}

std::string armadillo::errmsg(std::string s, std::string d)
{
	std::stringstream ss;
	ss << __progname << ": " << s << ": " << d << std::endl;
	return ss.str();
}

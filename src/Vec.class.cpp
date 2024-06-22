#include <Vec.class.hpp>

Vec::Vec(void) {}

Vec::Vec(const int x, const int y): _x(x), _y(y) {}

Vec::Vec(const Vec& copy) {
	*this = copy;
}

Vec&	Vec::operator=(const Vec& src) {
	if (this != &src) {
		this->_x = src._x;
		this->_y = src._y;
	}
	return (*this);
}

Vec::~Vec(void) {}

const int&	Vec::x(void) const {
	return (this->_x);
}

const int&	Vec::y(void) const {
	return (this->_y);
}

void	Vec::x(const int x) {
	this->_x = x;
}

void	Vec::y(const int y) {
	this->_y = y;
}

std::ostream&	operator<<(std::ostream& out, const Vec& src) {
	out << "(" << src.x() << ", " << src.y() << ")" << std::endl;
	return (out);
}

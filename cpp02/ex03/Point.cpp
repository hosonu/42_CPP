#include "Point.hpp"


Point::Point() : x(0), y(0) {
}

Point::Point(const float x, const float y) : x(x), y(y) {
}

Point::Point(const Point &src) {
	*this = src;
}

Point& Point::operator=(const Point &rhs) {
	if (this != &rhs)
		new (this)Point(rhs.getX().toFloat(), rhs.getY().toFloat());
	return *this;
}

Point::~Point() {
}

Fixed	Point::getX() const {
	return this->x;
}

Fixed	Point::getY() const {
	return this->y;
}

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::~Point() {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
}

Point& Point::operator=(const Point& other) {
    (void)other;
    return *this;
}

float Point::getX() const {
    return _x.toFloat();
}

float Point::getY() const {
    return _y.toFloat();
}
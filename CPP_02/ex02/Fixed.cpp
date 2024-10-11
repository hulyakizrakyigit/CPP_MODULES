#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointVal(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int val) : _fixedPointVal(val << _fractionalBits) {}

Fixed::Fixed(const float val) : _fixedPointVal(roundf(val * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) {
    operator=(other);
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_fixedPointVal = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
	return this->_fixedPointVal;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointVal = raw;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPointVal / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointVal >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
//comprasion operators
bool Fixed::operator>(const Fixed &other) const {
    return (this->_fixedPointVal > other._fixedPointVal);
}

bool Fixed::operator<(const Fixed &other) const {
    return (this->_fixedPointVal < other._fixedPointVal);
}

bool Fixed::operator>=(const Fixed &other) const {
    return (this->_fixedPointVal >= other._fixedPointVal);
}

bool Fixed::operator<=(const Fixed &other) const {
    return (this->_fixedPointVal <= other._fixedPointVal);
}

bool Fixed::operator==(const Fixed &other) const {
    return (this->_fixedPointVal == other._fixedPointVal);
}

bool Fixed::operator!=(const Fixed &other) const {
    return (this->_fixedPointVal != other._fixedPointVal);
}

//arithmetic operators
float Fixed::operator+(const Fixed &other) const {
    return this->toFloat() + other.toFloat();
}

float Fixed::operator-(const Fixed &other) const {
    return this->toFloat() - other.toFloat();
}

float Fixed::operator*(const Fixed &other) const {
    return this->toFloat() * other.toFloat();
}

float Fixed::operator/(const Fixed &other) const {
    return this->toFloat() / other.toFloat();
}

//increment and decrement operators
Fixed& Fixed::operator++() {
    this->_fixedPointVal += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    operator++();
    //++(*this);
    return tmp;
}

Fixed& Fixed::operator--() {
    this->_fixedPointVal -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    operator--();
    return tmp;
}

//static func.
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b; //a.operator<(b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b; //a.operator>(b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
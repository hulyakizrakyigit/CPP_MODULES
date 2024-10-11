#include "Fixed.hpp"

Fixed::Fixed() : _val(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	this->_val = val << _fractionalBits;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	this->_val = roundf(val * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	operator=(other);
	//*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_val = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_val;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_val / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_val >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

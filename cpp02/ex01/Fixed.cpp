#include "Fixed.hpp"

Fixed::Fixed() {
	_fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value ) {
	std::cout << "Default int constructor called" << std::endl;
	_fixedPoint = value << _fractBits;
}

Fixed::Fixed( const float number ) {
	std::cout << "Default float constructor called" << std::endl;
	_fixedPoint = number / (1 << _fractBits);
}

Fixed::Fixed(const Fixed& f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f) { 
	_fixedPoint = f._fixedPoint;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

float	Fixed::toFloat( void ) const {
	return (_fixedPoint / (1 << _fractBits));
}

int	Fixed::toInt ( void ) const { 
	return (_fixedPoint >> _fractBits);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void Fixed::setRawBits( int const raw ) {
	_fixedPoint = raw;
}

std::ostream& operator<<(std::ostream& os, Fixed& const fix) {
	os << fix.toFloat();
	return os;
}
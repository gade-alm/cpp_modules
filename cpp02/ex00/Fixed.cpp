#include "Fixed.hpp"

Fixed::Fixed() {
	_fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f) { 
	_fixedPoint = f._fixedPoint;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::Fixed(const Fixed& f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void Fixed::setRawBits( int const raw ) {
	_fixedPoint = raw;
}


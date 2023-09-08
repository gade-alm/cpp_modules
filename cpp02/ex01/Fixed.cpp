#include "Fixed.hpp"

Fixed::Fixed() {
	_fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

//copy constructor
Fixed::Fixed (const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(obj.getRawBits());
}

Fixed& Fixed::operator=( const Fixed& obj){
	std::cout << "Copy assignment operator called" << std::endl;
	obj.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits function called" << std::endl;
	return (_fixedPoint);
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedPoint = raw;
}
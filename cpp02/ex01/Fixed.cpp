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
	*this = obj;
}

Fixed& Fixed::operator=( const Fixed& obj){
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPoint = obj._fixedPoint;
	return (*this);
}

//converts integer to the corresponding fixed point value
Fixed::Fixed( const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = integer * (1 >> _fractBits);
}

//converts float to the corresponding fixed point value
Fixed::Fixed( const float floating_value ) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(floating_value * (1 << _fractBits));
}

//that converts the fixed-point value to a floating-point value
float	Fixed::toFloat( void ) const {
	return ((1.0 * abs(_fixedPoint)) / (1 << _fractBits));
}

//that converts the fixed-point value to an integer value.
int		Fixed::toInt( void ) const {
	return (this->_fixedPoint / 1 >> this->_fractBits);
}

int		Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits function called" << std::endl;
	return (_fixedPoint);
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedPoint = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}
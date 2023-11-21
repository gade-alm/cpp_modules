#include "Fixed.hpp"

Fixed::Fixed( void ) {
	_fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy ){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed( const int& value ){
	std::cout << "Int constructor called" << std::endl;
	_fixed = value << _bits;
}

Fixed::Fixed( const float& value ){
	std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(value * (1 << _bits));
}

Fixed& Fixed::operator=( const Fixed& copy ){
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(copy.getRawBits());
	return (*this);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed);
}

void	Fixed::setRawBits( int const raw ) {
	_fixed = raw;
}

int		Fixed::toInt( void ) const {
	return (_fixed >> _bits);
}

float	Fixed::toFloat( void ) const {
	return (((float)_fixed) / (float)(1 << _bits));
}

std::ostream& operator<<( std::ostream& os, const Fixed& obj ) {
	os << obj.toFloat();
	return (os);
}
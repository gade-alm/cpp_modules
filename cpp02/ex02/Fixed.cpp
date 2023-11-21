#include "Fixed.hpp"

Fixed::Fixed( void ) {
	_fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const Fixed& copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed( const int& value ) {
	std::cout << "Int constructor called" << std::endl;
	_fixed = value * (1 << _bits);
}

Fixed::Fixed( const float& value ) {
	std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(value * (1 << _bits));
}

Fixed& Fixed::operator=( const Fixed& copy ){
	// std::cout << "Copy assignment operator called" << std::endl;
	_fixed = copy._fixed;
	return (*this);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits function called" << std::endl;
	return (_fixed);
}

void	Fixed::setRawBits( int const raw ) {
	_fixed = raw;
}

int		Fixed::toInt( void ) const {
	return (_fixed / 1 >> _bits);
}

float	Fixed::toFloat( void ) const {
	return (((float)(_fixed)) / (float)(1 << _bits));
}

std::ostream& operator<<( std::ostream& os, const Fixed& copy ) {
	os << copy.toFloat();
	return (os);
}

Fixed Fixed::operator+( const Fixed& copy ) {
	return (this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-( const Fixed& copy ) { 
	return (this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator*( const Fixed& copy ) { 
	return (this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/( const Fixed& copy ) {
	return (this->toFloat() / copy.toFloat());
}

//Pre-increment
Fixed Fixed::operator++ ( ){
	++_fixed;
	return (*this);
}

//Pre-Increment
Fixed Fixed::operator-- ( ){
	--_fixed;
	return (*this);
}

//Post-increment
Fixed Fixed::operator++ ( int ){
	Fixed temp(*this);
	temp.operator++();
	return (temp);
}

//Post-increment
Fixed Fixed::operator-- ( int ){
	Fixed temp(*this);
	temp.operator--();
	return (temp);
}

bool Fixed::operator>( const Fixed& copy ) {
	return (this->_fixed > copy._fixed);
}

bool Fixed::operator<( const Fixed& copy ) {
	return (!operator>(copy._fixed));
}

bool Fixed::operator>=( const Fixed& copy ) {
	return (this->_fixed >= copy._fixed);
}

bool Fixed::operator<=( const Fixed& copy ) {
	return (this->_fixed <= copy._fixed);
}

bool Fixed::operator==( const Fixed& copy ) {
	return (this->_fixed == copy._fixed);
}

bool Fixed::operator!=( const Fixed& copy ) {
	return (this->_fixed != copy._fixed);
}

//compare functions

Fixed& Fixed::min( Fixed& lhs, Fixed& rhs ) { 
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed& Fixed::max( Fixed& lhs, Fixed& rhs ) {
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed& Fixed::min( const Fixed &lhs, const Fixed &rhs ) {
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed& Fixed::max( const Fixed &lhs, const Fixed &rhs ) {
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);	
}

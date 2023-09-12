#include "Fixed.hpp"

//Constructors and Destructors
Fixed::Fixed() {
	_fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

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
	this->_fixedPoint = integer * (1 << _fractBits);
}

//converts float to the corresponding fixed point value
Fixed::Fixed( const float floating_value ) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(floating_value * (1 << _fractBits));
}


//Conversions fixed_point flot and int
//that converts the fixed-point value to a floating-point value
float	Fixed::toFloat( void ) const {
	return ((1.0 * abs(_fixedPoint)) / (1 << _fractBits));
}

//that converts the fixed-point value to an integer value.
int		Fixed::toInt( void ) const {
	return (this->_fixedPoint / 1 >> this->_fractBits);
}


//Get and set values
int		Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits function called" << std::endl;
	return (_fixedPoint);
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedPoint = raw;
}


//Overloads
Fixed Fixed::operator+( const Fixed& obj ) {
	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-( const Fixed& obj ) { 
	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator*( const Fixed& obj ) { 
	return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/( const Fixed& obj ) {
	return (this->toFloat() / obj.toFloat());
}

//Pre-increment
Fixed Fixed::operator++ ( ){
	++_fixedPoint;
	return (*this);
}

//Pre-Increment
Fixed Fixed::operator-- ( ){
	--_fixedPoint;
	return (*this);
}

//Post-increment
Fixed Fixed::operator++ ( int ){
	Fixed temp(*this);
	operator++();
	return (temp);
}

//Post-increment
Fixed Fixed::operator-- ( int ){
	Fixed temp(*this);
	operator--();
	return (temp);
}

bool Fixed::operator>( const Fixed& obj ) {
	return (this->_fixedPoint > obj._fixedPoint);
}

bool Fixed::operator<( const Fixed& obj ) {
	return (!operator>(obj._fixedPoint));
}

bool Fixed::operator>=( const Fixed& obj ) {
	return (this->_fixedPoint >= obj._fixedPoint);
}

bool Fixed::operator<=( const Fixed& obj ) {
	return (this->_fixedPoint <= obj._fixedPoint);
}

bool Fixed::operator==( const Fixed& obj ) {
	return (this->_fixedPoint == obj._fixedPoint);
}

bool Fixed::operator!=( const Fixed& obj ) {
	return (this->_fixedPoint != obj._fixedPoint);
}

//output stream
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}

//compare functions

static Fixed& min( Fixed& lhs, Fixed& rhs ) { 
	
}

static Fixed& max ( Fixed& lhs, Fixed& rhs ) {

}

static const Fixed& min ( const Fixed &lhs, const Fixed &rhs ) {

}

static const Fixed& max (const Fixed &lhs, const Fixed &rhs) {

}

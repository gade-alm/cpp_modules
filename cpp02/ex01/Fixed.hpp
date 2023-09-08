#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
	private:
		int 				_fixedPoint;
		static const int 	_fractBits = 8;
	public:
		Fixed();
		Fixed( const Fixed& obj) ;
		Fixed& operator=( const Fixed& obj);
		~Fixed();
		Fixed( const int integer );
		Fixed( const float floating_value );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const; //that converts the fixed-point value to a floating-point value
		int		toInt ( void ) const; //that converts the fixed-point value to an integer value.
};

std::ostream& operator<<(std::ostream& os, Fixed& fix);

#endif
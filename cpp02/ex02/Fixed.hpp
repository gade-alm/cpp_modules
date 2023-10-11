#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed{
	private:
		int					_fixedPoint;
		static const int	_fractBits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed& obj );
		Fixed& operator=( const Fixed& obj );
		~Fixed( void );
		Fixed( const int integer );
		Fixed( const float floating_value );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const; //that converts the fixed-point value to a floating-point value
		int		toInt ( void ) const; //that converts the fixed-point value to an integer value.

		Fixed operator+( const Fixed& obj );
		Fixed operator-( const Fixed& obj );
		Fixed operator*( const Fixed& obj );
		Fixed operator/( const Fixed& obj );
		Fixed operator++();
		Fixed operator--();
		Fixed operator++( int );
		Fixed operator--( int );
		bool operator>( const Fixed& obj );
		bool operator<( const Fixed& obj );
		bool operator>=( const Fixed& obj );
		bool operator<=( const Fixed& obj );
		bool operator==( const Fixed& obj );
		bool operator!=( const Fixed& obj );

		static Fixed& min( Fixed& lhs, Fixed& rhs );
		static Fixed& max ( Fixed& lhs, Fixed& rhs );
		static const Fixed& min ( const Fixed &lhs, const Fixed &rhs );
		static const Fixed& max ( const Fixed &lhs, const Fixed &rhs );
};

std::ostream& operator<<( std::ostream& os, const Fixed& obj );

#endif
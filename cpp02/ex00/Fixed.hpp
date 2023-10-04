#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
	private:
		int 				_fixedPoint;
		static const int 	_fractBits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed& obj );
		Fixed& operator=( const Fixed& obj );
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};


#endif
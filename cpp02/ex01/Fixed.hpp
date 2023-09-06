#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
	private:
		int 				_fixedPoint;
		static const int 	_fractBits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float number);
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& f);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt ( void ) const;
};

std::ostream& operator<<(std::ostream& os, Fixed& fix);

#endif
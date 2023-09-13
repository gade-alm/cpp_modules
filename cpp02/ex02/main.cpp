#include "Fixed.hpp"

int main( void ) {
	{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "--------------------SECOND TEST BATTERY--------------------" << std::endl;
	Fixed	test;
	Fixed	test2;
	Fixed	const obj2( Fixed( 3.05f ));
	Fixed	const obj( Fixed( 2.03f ) * Fixed(4) );

	std::cout << "TEST: " << test << std::endl;
	std::cout << "++TEST: " << ++test << std::endl;
	std::cout << "TEST: " << test << std::endl;
	std::cout << "--TEST: " << --test << std::endl;
	test2 = test2 + 2;

	std::cout << "MAX CONST " << Fixed::max( obj2, obj ) << std::endl;
	std::cout << "MIN CONST " << Fixed::min( obj2, obj ) << std::endl;
	std::cout << "MAX " << Fixed::max( test, test2 ) << std::endl;
	std::cout << "MIN " << Fixed::min( test, test2 ) << std::endl;
	return 0;
}

/* $> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$> */
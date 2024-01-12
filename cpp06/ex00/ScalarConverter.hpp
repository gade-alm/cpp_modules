#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define MAX_INT 2147483647
#define MIN_INT -2147483648

class ScalarConverter {
	private: 
		ScalarConverter ( void );
		ScalarConverter ( ScalarConverter& copy );
		ScalarConverter& operator=( ScalarConverter& copy );
	public:
		~ScalarConverter ( void );
		static void	convert ( const std::string &av );
};

void	printPseudos( std::string value );
int		getType ( std::string value );
int		checkChar( std::string value );
int		checkInt( std::string value );
int		checkFloat( std::string value );
int		checkDouble( std::string value );
void	printChar( std::string value );
void	printInt( std::string value );
void	printFloat( std::string value );
void	printDouble( std::string value );

#endif

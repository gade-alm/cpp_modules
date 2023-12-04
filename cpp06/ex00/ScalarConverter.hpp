#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

#define CHAR 1
#define FLOAT 2

class ScalarConverter {
	private: 
		ScalarConverter ( void );
		ScalarConverter ( ScalarConverter& copy );
		ScalarConverter& operator=( ScalarConverter& copy );
	public:
		~ScalarConverter ( void );
		static void	convert ( const std::string &av );
};

#endif
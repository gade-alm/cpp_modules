#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {
}

ScalarConverter::~ScalarConverter ( void ) {
}

ScalarConverter::ScalarConverter( ScalarConverter& copy ) {
	(void)copy;
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=( ScalarConverter& copy ) {
	(void)copy;
	return *this;
}

void	ScalarConverter::convert( const std::string& av ){
	
	std::string	charValue = "";
	int 	type = 0;
	float	floatValue = 0;

	for (size_t i = 0; i < av.length(); i++)
	{
		if (av.length() == 1 && isprint(av[0]) && !isdigit(av[0])){
			type = CHAR;
			break ;
		}
		if (std::atof(av.c_str()) != 0){
			floatValue = std::atof(av.c_str());
			type = FLOAT;
			break ;
		}
	}
	switch (type) {
		case 1: {
			charValue = av[0];
			std::cout << "Char: " << "'" << charValue << "'" <<std::endl;
			std::cout << "Int: " << static_cast<int>(charValue[0]) << std::endl;
			std::cout << "Float: " << std::fixed << std::setprecision(3) << static_cast<float>(charValue[0]) << 'f' << std::endl;
			std::cout << "Double: " << std::fixed << std::setprecision(3) << static_cast<double>(charValue[0]) << std::endl;
			break ;
		}
		case 2: {
			if (floatValue > 31 && floatValue < 128)
				charValue = static_cast<char>(floatValue);
			else
				charValue = "Can't be printed";
			std::cout << "Char: " << "'" << charValue << "'" << std::endl;
			std::cout << "Int: " << static_cast<int>(floatValue) << std::endl;
			std::cout << "Float: " << std::fixed << std::setprecision(3) << floatValue << 'f' << std::endl;
			std::cout << "Double: " << std::fixed << std::setprecision(3) << static_cast<double>(floatValue) << std::endl;
			break ;
		}
		default: {
			std::cout << "Error on parameters, check again" << std::endl;
			break ;
		}
	}
}


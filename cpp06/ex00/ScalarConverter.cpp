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
	int 	type = getType(av);

	std::cout << "---------------------------CONVERSION VALUES---------------------------" << std::endl;
	switch (type) {
		case 1: {
			std::cout << "You sent a CHAR" << std::endl;
			printChar(av);
			return ;
		}
		case 2: {
			std::cout << "You sent an INT" << std::endl;
			printInt(av);
			return ;
		}
		case 3: {
			std::cout << "You sent a FLOAT" << std::endl;
			printFloat(av);
			return ;
		}
		case 4: {
			std::cout << "You sent a DOUBLE" << std::endl;
			printDouble(av);
			return ;
		}
		default: {
			std::cout << "Error on parameters, check again" << std::endl;
			return ;
		}
	}
}

int	getType( std::string value ) {

	if (checkChar(value) != -1)
		return (CHAR);
	if (checkInt(value) != -1)
		return (INT);
	if (checkFloat(value) != -1)
		return (FLOAT);
	if (checkDouble(value) != -1)
		return (DOUBLE);
	return (-1);
}

int	checkChar( std::string value ) {
	if (value.size() == 1 && isprint(value[0]) && !isdigit(value[0])){ 
		return (CHAR);
	}
	return (-1);
}

int checkInt( std::string value ) { 
	size_t i = 0;

	if (value[i] == '-' || value[i] == '+')
		i++;
	for (; i < value.length() && isdigit(value[i]); i++) {
	}
	if (value[i] != '\0')
		return (-1);
	return (INT);
}

int	checkFloat( std::string value ) {
	size_t i = 0, check = 0, fTotal = 0, numbers = 0;

	if (value[i] == '-' || value[i] == '+')
		i++;
	for (; i < value.length(); i++) {	
		if (value[i] == '.')
			check++;
		if (value[i] == 'f')
			fTotal++;
		if (isdigit(value[i]))
			numbers++;
	}
	if (value[i - 1] == 'f' && check == 1 && fTotal == 1 && numbers > 0) {
		return (FLOAT);
	}
	if (check == i || value[i] != '\0')
		return (-1);
	return (-1);
}

int	checkDouble( std::string value ) {
	size_t i = 0, check = 0;

	if (value[i] == '-' || value[i] == '+')
		i++;
	for (; i < value.length() && isdigit(value[i]); i++) {		
	}
	if (value[i] == '.') {
		check = i;
		i++;
	}
	for(; i < value.length() && isdigit(value[i]); i++) {
	}
	if (check == i || value[i] != '\0')
		return (-1);
	return (DOUBLE);
}

void	printInt( std::string value ) {

	long int myInt = std::atoll(value.c_str());

	if (myInt > 31 && myInt < 128)
		std::cout << "Char: " << "'" << static_cast<char>(myInt) << "'" << std::endl;
	else
		std::cout << "Char: Can't be printed" << std::endl;
	if (myInt > MAX_INT || myInt < MIN_INT) 
		std::cout << "Int: overflow value" << std::endl;
	else
		std::cout << "Int: " << myInt << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(myInt) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(myInt) << std::endl;
}

void	printFloat( std::string value ) {

	float myFloat = std::atof(value.c_str());

	if (myFloat > 31 && myFloat < 128)
		std::cout << "Char: " << "'" << static_cast<char>(myFloat) << "'" << std::endl;
	else
		std::cout << "Char: Can't be printed" << std::endl;
	if (static_cast<int>(myFloat) >= MAX_INT ||static_cast<int>(myFloat) <= MIN_INT) 
		std::cout << "Int: overflow value" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(myFloat) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << (myFloat) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(myFloat) << std::endl;
}

void	printChar( std::string value ) {

	char	charValue;

	charValue = value[0];
	std::cout << "Char: " << "'" << charValue << "'" <<std::endl;
	std::cout << "Int: " << static_cast<int>(charValue) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(charValue) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(charValue) << std::endl;
}

void	printDouble( std::string value ) {

	double myDouble = strtod(value.c_str(), NULL);

	if (myDouble > 31 && myDouble < 128)
		std::cout << "Char: " << "'" << static_cast<char>(myDouble) << "'" << std::endl;
	else
		std::cout << "Char: Can't be printed" << std::endl;
	if (myDouble > MAX_INT || myDouble < MIN_INT) 
		std::cout << "Int: overflow value" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(myDouble) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << (myDouble) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << myDouble << std::endl;
}

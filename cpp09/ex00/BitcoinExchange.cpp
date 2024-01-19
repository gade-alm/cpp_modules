#include "BitcoinExchange.hpp"

void	openDatabase( char* baseName ) {

	std::ifstream				input;

	input.open( baseName );
	if (!input.is_open()) {
		std::cout << "Couldn't open input, please check your file" << std::endl;
		return ;
	}
	checkInput( input );
	std::ifstream			database;
	database.open( "data.csv" );
	if (!database.is_open()) {
		std::cout << "Couldn't open the database, please check your file" << std::endl;
	}
	makeConversion ( input, database );
}

void	checkConversion( std::string value ) {

	float	money;

	money = std::atof(value.substr(value.find_last_of('|') + 1).c_str());
	if (money <= 0 || money >= 1000)
		throw std::out_of_range("Wrong money input value");
	return ;

}

void	checkInput( std::ifstream &base ) {

	std::string	checker;
	std::string	date;
	bool		first = false;

	while (getline(base, checker)) {
	try {
		if (!first) {
			if (checker != "date | value")
				throw std::runtime_error("Wrong header, check first line");
			first = true;
			continue ;
		}
		for (size_t i = 0; i < checker.size(); i++)
			if (!isdigit(checker[i]) && (checker[i] != '.' && checker[i] != '|' \
			&& checker[i] != '|' && checker[i] != '-' && checker[i] != 32))
				throw std::runtime_error("Wrong input, check your file");
		checkDate( checker );
		checkConversion( checker );
		}
	catch ( std::exception &e ) {
		std::cerr << e.what() << std::endl;
		}
	}
}

static bool checkLeapYear( unsigned int year ){
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	return 0;
}

bool	verifyDate( long long year, long long month, long long day ) {

	if (month == 2 && day == 29 && checkLeapYear(year))
		return 1;
	
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {
		if (day <= 31)
			return 1;
		}
		break ;
		case 4:
		case 6:
		case 9:
		case 11:{
		if (day <= 30)
			return 1;
		}
		break ;
		case 2: {
		if (day <= 28)
			return 1;
		}
		break ;
	}
	return 0;
}

void	checkDate( std::string date ) {

	long long	year = 0;
	long long	month = 0;
	long long	day = 0;

	std::string data = date.substr( 0, date.find('|') );
	if (data.size() < 8)
		throw std::out_of_range("Data in wrong pattern");
	year = atoll(date.substr(0, date.find('-')).c_str());
	if (year < 2010)
		throw std::out_of_range("The year is too low, check your input");
	month = atoll(date.substr(date.find('-') + 1, '-').c_str());
	day = atoll(date.substr(date.find_last_of('-') + 1).c_str());
	if (!verifyDate( year, month, day ))
		throw std::out_of_range("Wrong date input");
	return ;
}

void	makeConversion ( std::ifstream &input, std::ifstream &database ) {

	std::string bitcoin;
	std::map	<std::string, float> bitmap;
	std::map	<std::string, float> inpmap;

	(void)input;
	while (getline(database, bitcoin)) {
		std::cout << bitcoin << std::endl;
	}
}
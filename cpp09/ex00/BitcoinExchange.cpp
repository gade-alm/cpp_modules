#include "BitcoinExchange.hpp"

void	openDatabase( char* baseName ) {

	std::ifstream				input;

	input.open( baseName );
	if (!input.is_open()) {
		std::cout << "Couldn't open input, please check your file" << std::endl;
		return ;
	}
	std::ifstream			database;
	database.open( "data.csv" );
	if (!database.is_open()) {
		std::cout << "Couldn't open the database, please check your file" << std::endl;
		return ;
	}
	makeConversion( input, database );
}

void	makeConversion ( std::ifstream & input, std::ifstream & database ) {

	std::string checker;
	(void)database;

	while (getline(input, checker)){
		checkDate(checker);	
	}
}

static bool	checkPattern(std::string &str) {

	for (int i = 0; str[i]; i++) {
		if (i < 4 && !isdigit(str[i]))
			return 1;
		if (str[5] != '-')
			return 1;
	}
	return 0;
}

std::string	checkDate( std::string checker ) {

	// const char* date = checker.c_str();
	// int			i = 0;
	int			year;
	int			month;
	int			day;

	if (checkPattern(checker))
		std::cout << "Verify date input, wrong size" << std::endl;
	year = atoi(checker.substr(0, checker.find('-')).c_str());
	if (year < 2009 || year > 2024) {
		return "Wrong year input";
	}
	month = atoi(checker.substr(checker.find('-') + 1, checker.find('-')).c_str());
	if (month < 1 || month > 12) {
		std::cout << "Wrong month input" << std::endl;
		return "Wrong month input";
	}
	day = atoi(checker.substr(checker.find('|') - 3).c_str());
	if (day < 1 || day > 31) {
		std::cout << "Wrong day input" << std::endl;
		return "Wrong day input";
	}
	if (!verifyDate(year, month, day))
		std::cout << "Wrong date values" << std::endl;
	std::cout << "this one is correct: " << checker << std::endl;
	return "";
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

bool	verifyDate( int year, int month, int day ) {

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

// void	checkDate( std::string date ) {

// 	long long	year = 0;
// 	long long	month = 0;
// 	long long	day = 0;

// 	std::string data = date.substr( 0, date.find('|') );
// 	if (data.size() < 8)
// 		throw std::out_of_range("Data in wrong pattern");
// 	year = atoll(date.substr(0, date.find('-')).c_str());
// 	if (year < 2010)
// 		throw std::out_of_range("The year is too low, check your input");
// 	month = atoll(date.substr(date.find('-') + 1, '-').c_str());
// 	day = atoll(date.substr(date.find_last_of('-') + 1).c_str());
// 	if (!verifyDate( year, month, day ))
// 		throw std::out_of_range("Wrong date input");
// 	return ;
// }

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

static bool checkValue ( std::string checker ) {

	float	check = 0;
	for (size_t i = 0; i < checker.size(); i++) {
		if (checker[i] == '|'){
			check = atof(checker.substr(checker.find_last_of('|') + 1).c_str());
			if (check < 0 || check > 1000)
				return 1;
		}
	}
	return 0;
}

void	makeConversion ( std::ifstream & input, std::ifstream & database ) {

	std::string 					checker;
	bool							firstLine = 0;
	std::string						databaseValues;
	std::map<std::string, float>	dataMap;

	while (std::getline(database, databaseValues))
		dataMap[databaseValues.substr(0, databaseValues.find(',')).c_str()] = atof(databaseValues.substr(databaseValues.find_last_of(',') + 1).c_str());
	while (getline(input, checker)){
		if (firstLine == 0) {
			if (checker.compare("date | value"))
				std::cout << "Date | value missing or wrong -> " << checker << std::endl;
			firstLine = 1;
			continue ;
		}
		if (checker[11] != '|') {
			std::cout << "Wrong input, please check the line -> " << checker << std::endl;
			continue ;
		}
		if (checkValue(checker)) {
			std::cout << "Wrong value input, can't convert -> " << checker << std::endl;
			continue ;
		}
		if (checkDate(checker) == "")
			printConversion ( checker, dataMap );
		else
			std::cout << checkDate(checker) << std::endl;;

	}
}

static float		getValue ( std::string checker ) {
	return (atof(checker.substr(checker.find_last_of('|') + 1).c_str()));
}

void	printConversion( std::string checker, std::map<std::string, float>dataMap ){

	std::map<std::string, float>::iterator	dataite;
	std::map<std::string, float>::iterator lastValue;
	std::string								databaseValues;

	for (dataite = dataMap.begin(); dataite != dataMap.end(); dataite++) {
		if (dataite->first == checker.substr(0, checker.find('|') - 1)) 
			return (void)(std::cout << dataite->first << " => " << getValue(checker) * dataite->second << std::endl);
		if (dataite->first > checker.substr(0, checker.find('|') - 1)) 
			return (void)(std::cout << lastValue->first << " => " << getValue(checker) * lastValue->second << std::endl);
		lastValue = dataite;
		}
	return ;
}

static bool	checkPattern(const char *str) {

	struct tm time;

	if (!strptime(str, "%Y-%m-%d", &time))
		return 1;
	return 0;
}

std::string	checkDate( std::string checker ) {

	int			year;
	int			month;
	int			day;

	if (checkPattern(checker.c_str())) 
		return "Verify date input -> " + checker;
	year = atoi(checker.substr(0, checker.find('-')).c_str());
	if (year < 2009 || year > 2024) 
		return "Wrong year input, out of range -> " + checker;
	month = atoi(checker.substr(checker.find('-') + 1, checker.find('-')).c_str());
	day = atoi(checker.substr(checker.find('|') - 3).c_str());
	if (!verifyDate(year, month, day)) 
		return "Wrong date values -> " + checker;
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



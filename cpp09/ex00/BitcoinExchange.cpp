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
		return ;
	}
	input.seekg(0, input.beg);
	makeConversion ( input, database );
}

static int	checkConversion( std::string value ) {

	float	money;

	money = std::atof(value.substr(value.find_last_of('|') + 1).c_str());
	if (money <= 0 || money >= 1000) {
		std::cout << "Wrong money input value" << std::endl;
		return 1;
	}
	return 0;

}

void	checkInput( std::ifstream &base ) {

	std::string	checker;
	std::string	date;
	bool		first = false;

	while (getline(base, checker)) {
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
		// checkDate( checker );
		checkConversion( checker );
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

static int	checkDateReturn ( std::string date ) {

	long long	year = 0;
	long long	month = 0;
	long long	day = 0;

	std::string data = date.substr( 0, date.find('|') );
	if (data.size() < 8)
		return 1;
	year = atoll(date.substr(0, date.find('-')).c_str());
	if (year < 2010)
		return 1;
	month = atoll(date.substr(date.find('-') + 1, '-').c_str());
	day = atoll(date.substr(date.find_last_of('-') + 1).c_str());
	if (!verifyDate( year, month, day ))
		return 1;
	return 0;
}

void	makeConversion ( std::ifstream &input, std::ifstream &database ) {

	std::string 						inputValues;
	std::string							databaseValues;
	std::map	<std::string, float>	inputMap;
	std::map	<std::string, float> 	bitMap;
	std::map 	<std::string, float>::iterator itinp;
	std::map	<std::string, float>::iterator itdat;
	bool								first = 0;

	input.clear();
	input.seekg(0);
	(void)database;
	while (std::getline(input, inputValues)) {
		if (!first) {
			first = true;
			continue ;
		}
		for (size_t i = 0; i < inputValues.size(); i++)
			if (!isdigit(inputValues[i]) && (inputValues[i] != '.' && inputValues[i] != '|' \
			&& inputValues[i] != '|' && inputValues[i] != '-' && inputValues[i] != 32))
				std::cout << "Wrong input, check your line" << std::endl;
		else if (checkDateReturn( inputValues ))
			std::cout << "Wrong date input, check your dates" << std::endl;
		else if (checkConversion( inputValues ))
			std::cout << "Wrong value, check your input values" << std::endl;
	}
}
	// 	inputMap[inputValues.substr(0, inputValues.find('|') - 1).c_str()] = atof(inputValues.substr(inputValues.find_last_of('|') + 1).c_str());
	// while (std::getline(database, databaseValues))
	// 	bitMap[databaseValues.substr(0, databaseValues.find(',')).c_str()] = atof(databaseValues.substr(databaseValues.find_last_of(',') + 1).c_str());
	
	// for (itinp = inputMap.begin(); itinp != inputMap.end(); itinp++)
	// {
	// 	for (itdat = bitMap.begin(); itdat != bitMap.end(); itdat++){
	// 		if (itinp->first == itdat->first) {
	// 			std::cout << itinp->first << " => " << itinp->second << " = " << (itinp->second * itdat->second) << std::endl;
	// 			break ;
			// }
			// else if (itinp->first > itdat->first) {
			// 	itdat--;
			// 	std::cout << itinp->first << " => " << itinp->second << " = " << (itinp->second * itdat->second) << std::endl;
			// 	break ;
// 			}
// 		}
// 	}
// }
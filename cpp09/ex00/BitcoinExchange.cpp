#include "BitcoinExchange.hpp"

void	openDatabase( char* baseName ) {

	std::ifstream					database;
	std::map<std::string, float>	inputs;

	database.open( baseName );
	if (!database.is_open()) {
		std::cout << "Couldn't open database, please check your file" << std::endl;
		return ;
	}
	checkInput( database );
}

float	makeConversion( std::string value ) {

	float	money;

	money = std::atof(value.substr(value.find_last_of('|') + 1).c_str());
	if (money <= 0 || money >= 1000)
		throw std::out_of_range("Wrong money input value");
	return money;

}

void	checkInput( std::ifstream &base ) {

	std::string	checker;
	std::string	date;
	float		money;

	while (getline(base, checker)) {
	try {
		for (size_t i = 0; i < checker.size(); i++)
			if (!isdigit(checker[i]) && (checker[i] != '.' && checker[i] != '|' \
			&& checker[i] != '|' && checker[i] != '-' && checker[i] != 32))
				std::cout << "WRONG INPUT TEST " << checker[i] << std::endl;
		date = checkDate( checker );
		money = makeConversion( checker );
		configureMap ( date, money );
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

bool	checkDate( long long year, long long month, long long day ) {

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
		case 2:
		case 4:
		case 6:
		case 9:
		case 11:{
		if (day <= 30)
			return 1;
		}
		break ;
	}
	return 0;
}

std::string	checkDate( std::string date ) {

	long long	year = 0;
	long long	month = 0;
	long long	day = 0;

	std::string data = date.substr( 0, date.find('|') );
	if (data.size() < 8)
		throw std::out_of_range("Data in wrong pattern");
	year = atoll(date.substr(0, date.find('-')).c_str());
	month = atoll(date.substr(date.find('-') + 1, '-').c_str());
	day = atoll(date.substr(date.find_last_of('-') + 1).c_str());
	if (!checkDate( year, month, day ))
		throw std::out_of_range("Wrong date input");
	return data;
}

void	configureMap( std::string date, float money ) {
	
	std::map<std::string, float> maps;

	maps.insert(std::pair<std::string, float>(date, money));
	std::map<std::string, float>::iterator itr;
    for( itr=maps.begin(); itr!=maps.end() ;itr++) 
    {
        std::cout << itr->first <<" "<< itr->second << std::endl;
    }
}
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>

/*

1	Should receive a file (DONE)
2	Should receive a file.txt (must be a date | value format) (DONE)
3	Verify each date if its valid (DONE)
4	A valid date is Year-Month-Day (DONE)
5	Verify each value if its a int or float and between 0 and 1000 (DONE)
6	If all is valid, compare if the date of the txt exists on csv 
6.1		If exists, multiply the value of the .txt with the value of the date on .csv
6.2		If doesn't exist, find the closest one going back on time and multiply

*/ 

void		openDatabase( char* baseName );
void		checkInput( std::ifstream &base );
void		checkDate( std::string date );
void		checkConversion( std::string value );
void		makeConversion( std::ifstream &input, std::ifstream &database );

#endif
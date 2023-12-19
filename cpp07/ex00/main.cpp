#include "templates.hpp"

int main ( void ) {
	{
	int num1 = 5;
	int num2 = 10;

	std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
	::swap(num1, num2);
	std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;

	std::cout << "Max value: " << max(num1, num2) << std::endl;
	std::cout << "Min Value: " << min(num1, num2) << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	{
	char char1 = 'a';
	char char2 = 'z';

	std::cout << "char1: " << char1 << " char2: " << char2 << std::endl;
	swap(char1, char2);
	std::cout << "char1: " << char1 << " char2: " << char2 << std::endl;

	std::cout << "Max value: " << static_cast<char>(max(char1, char2)) << std::endl;
	std::cout << "Min Value: " << static_cast<char>(min(char1, char2)) << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	{
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}
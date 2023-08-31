#include <iostream>
#include <string>

int main(void)
{
	std::string example = "HI THIS IS BRAIN";
	std::string *ptr = &example;
	std::string &ref = example;

	std::cout << "Memory Adress string:" << &example << std::endl;
	std::cout << "Memory Adress pointer:" << &ptr << std::endl;
	std::cout << "Memory Adress reference:" << &ref << std::endl;
	std::cout << "Value of string:" << example << std::endl;
	std::cout << "Value of pointer:" << *ptr << std::endl;
	std::cout << "Value of reference:" << ref << std::endl;
}
#include "Bureaucrat.hpp"

int main( void ) {
	try {
		std::cout << "Trying grade 1" << std::endl;
		Bureaucrat highest ("Test 1", 1);
		std::cout << highest;
		}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 150" << std::endl;
		Bureaucrat highest ("Test 150", 150);
		std::cout << highest;
		}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 151" << std::endl;
		Bureaucrat highest ("Test 151", 151);
		std::cout << highest;
		}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 0" << std::endl;
		Bureaucrat highest ("Test 0", 0);
		std::cout << highest;
		}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 1" << std::endl;
		Bureaucrat highest ("TestDecrease 1", 1);
		std::cout << highest;
		std::cout << "Incrementing value by 1" << std::endl;
		highest.incrementGrade();
		std::cout << highest;
		}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 150" << std::endl;
		Bureaucrat highest ("TestIncrement 150", 150);
		std::cout << highest;
		std::cout << "Decreasing value by 1" << std::endl;
		highest.decreaseGrade();
		std::cout << highest;
		std::cout << "----------------------------------" << std::endl;
		}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
}

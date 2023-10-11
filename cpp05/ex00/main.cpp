#include "Bureaucrat.hpp"

int main( void ) {
	try {
		std::cout << "Trying grade 1" << std::endl;
		Bureaucrat highest ("Test1", 1);
		std::cout << highest;
		}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 150" << std::endl;
		Bureaucrat highest ("Test150", 150);
		std::cout << highest;
		}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 151" << std::endl;
		Bureaucrat highest ("Teste151", 151);
		std::cout << highest;
		}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 0" << std::endl;
		Bureaucrat highest ("Test0", 0);
		std::cout << highest;
		}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 1" << std::endl;
		Bureaucrat highest ("TestDecrease1", 1);
		std::cout << highest;
		std::cout << "Decreasing value by 2" << std::endl;
		highest.decreaseGrade(2);
		std::cout << highest;
		}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	try {
		std::cout << "Trying grade 150" << std::endl;
		Bureaucrat highest ("TestIncrement150", 150);
		std::cout << highest;
		std::cout << "Incrementing value by 2" << std::endl;
		highest.incrementGrade(2);
		std::cout << highest;
		std::cout << "----------------------------------" << std::endl;
		}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
}

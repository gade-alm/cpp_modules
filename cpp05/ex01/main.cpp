#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {
	{
	std::cout << "-------------TEST 1-------------" << std::endl;
	std::cout << "Grade too low test" << std::endl;

	try {
		std::cout << "Trying signForm" << std::endl;
		Bureaucrat gabriel("Gabriel", 50);
		Form		form("Formulary", 2, 5 );

		std::cout << gabriel << std::endl;
		std::cout << form << std::endl;
		form.beSigned(gabriel);
		gabriel.signForm(form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	{
	std::cout << "-------------TEST 2-------------" << std::endl;
	std::cout << "Grade is OK test" << std::endl;
	Bureaucrat gabriel("Gabriel", 1);
	Form		form("Formulary", 2, 5 );

	std::cout << gabriel << std::endl;
	std::cout << form << std::endl;
	try {
		std::cout << "Trying signForm" << std::endl;
		form.beSigned(gabriel);
		gabriel.signForm(form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	}
}
}
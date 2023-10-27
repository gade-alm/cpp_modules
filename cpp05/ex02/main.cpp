#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
	{
	try {
		ShrubberyCreationForm plant("Gabriel");
		Bureaucrat			bureau("Henrique", 135);
		bureau.signForm(plant);
		plant.execute(bureau);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	}
	std::cout << "----------------2nd Test----------------" << std::endl;
	{
	try {
		RobotomyRequestForm robot("Gabriel");
		Bureaucrat			burea("Henrique", 1);
		burea.signForm(robot);
		robot.execute(burea);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	}
		std::cout << "----------------3rd Test----------------" << std::endl;
	{
	try {
		PresidentialPardonForm president("Gabriel");
		Bureaucrat			bur("Henrique", 6);
		bur.signForm(president);
		president.execute(bur);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	}
}

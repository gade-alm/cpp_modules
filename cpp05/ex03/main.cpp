#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void ) {
	Intern estagiario;
	Bureaucrat gabriel("Gabriel", 1);
	AForm *formulary;

	{
	formulary = estagiario.makeForm("robotomy request", "Henrique");
	try {
		if (formulary != NULL) {
			formulary->beSigned(gabriel);
			formulary->execute(gabriel);
		}
		}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	delete formulary;
	}
	{
	formulary = estagiario.makeForm("presidential pardon", "Henrique");
	try {
		if (formulary != NULL) {
			formulary->beSigned(gabriel);
			formulary->execute(gabriel);
		}
		}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	delete formulary;
	}
	{
	formulary = estagiario.makeForm("shrubbery creation", "Henrique");
	try {
		if (formulary != NULL) {
			formulary->beSigned(gabriel);
			formulary->execute(gabriel);
		}
		}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	delete formulary;
	}
}

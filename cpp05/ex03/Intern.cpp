#include "Intern.hpp"

Intern::Intern( void ) {

}

Intern::~Intern( void ) {

}

Intern::Intern( const Intern& copy ) {
	*this = copy;
}

Intern& Intern::operator=( const Intern& copy ) {
	(void)copy;
	return (*this);
}

AForm* Intern::makeForm( std::string input, std::string name ) {
	std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int i = -1;
	AForm *ret;

	while (++i < 3)
		if (!forms[i].compare(input))
			break ;
	switch(i){
		case 0:
			std::cout << "Intern creates Robotomy Request Form" << std::endl;
			ret = new RobotomyRequestForm(name);
			break ;
		case 1:
			std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
			ret = new ShrubberyCreationForm(name);
			break ;
		case 2:
			std::cout << "Intern creates Presidential Pardon Form" << std::endl;
			ret = new PresidentialPardonForm(name);
			break ;
		default:
			std::cout << "Can't find any form with this name, please check again" << std::endl;
			ret = 0;
	}
	return (ret);
}
#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{ 
	private:
	public:
		Intern( void );
		~Intern( void );
		Intern( const Intern& copy );
		Intern& operator=( const Intern& copy );
		AForm* makeForm( std::string input, std::string name );
};

#endif

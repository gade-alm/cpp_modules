#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Presidential", 25, 5) {

}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("Presidential", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : AForm() {
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& copy ){
	_target = copy._target;
	return (*this);
}

std::string		PresidentialPardonForm::getTarget( void ) const {
	return _target;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	if (this->isSigned()) {
		if (this->getRequiredGrade() >= executor.getGrade()) {
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		}
		else
			std::cout << "The Presidential Form is signed but can't be executed" << std::endl;
	}
	else
		std::cout << "Can't execute the Presidential Form" << std::endl;
}

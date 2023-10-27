#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Robotomy", 72, 45) {

}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("Robotomy", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : AForm() {
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& copy ){
	_target = copy._target;
	return (*this);
}

std::string		RobotomyRequestForm::getTarget( void ) const {
	return _target;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	if (this->isSigned()) {
		if (this->getRequiredGrade() > executor.getGrade()) {
			std::cout << "Makes some drilling noises" << std::endl;
			srand((unsigned) time(0));
			if (rand() % 2 == 0)
				std::cout << _target << " is successfully robotomized" << std::endl;
			else
				std::cout << _target << " couldn't get robotomized" << std::endl;
		}
		else
			std::cout << "The Robotomy Form is signed but can't be executed" << std::endl;
	}
	else
		std::cout << "Can't execute the Robotomy Form" << std::endl;
}

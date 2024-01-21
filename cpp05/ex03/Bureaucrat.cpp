#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name(""), _grade(50) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat ( std::string name, int grade ) : _name(name), _grade(grade) {
	if (grade >= 151)
		throw GradeTooLowException();
	else if (grade <= 0)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat ( const Bureaucrat& copy ) : _name(copy._name) {
	*this = copy;
}

Bureaucrat& Bureaucrat::operator= ( const Bureaucrat& copy)  {
	_grade = copy._grade;
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too low");
}

int	Bureaucrat::decreaseGrade( void ) {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	return (_grade + 1);
}

int Bureaucrat::incrementGrade( void ) {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	return (_grade - 1);
}

const std::string& Bureaucrat::getName( void ) const {
	return _name;
}

int		Bureaucrat::getGrade( void ) const {
	return _grade;
}

bool	Bureaucrat::signForm ( AForm &form ) {
	if (form.beSigned(*this) == 1 && form.getSignGrade() >= _grade){
		std::cout << _name << " signed " << form.getName() << std::endl;
		return 1;
	}
	else
		std::cout << this->_name << " couldn't sign the form" << std::endl;
	return 0;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& obj ) {
	os << obj.getName() << " ,bureaucrat grade " << obj.getGrade() << std::endl;
	return os;
}
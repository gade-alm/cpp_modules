#include "Form.hpp"

Form::Form( void ) : _name(""), _signed(0), _signGrade(0), _requiredGrade(0){
}

Form::~Form( void ){
}

Form::Form( const Form& copy ) : _name("Dummy"), _signed(0), _signGrade(0), _requiredGrade(0){
	*this = copy;
}

Form::Form( const char* name, const int signGrade, const int requiredGrade) : _name(name), _signed(0), _signGrade(signGrade), _requiredGrade(requiredGrade){
}

Form& Form::operator=( const Form& copy ) {
	(void)copy;
	return (*this);
}

std::ostream& operator<<( std::ostream& os, const Form& obj ) {
	os << "Name: "<< obj.getName() << std::endl << "Signed: " << obj.isSigned() << std::endl \
	<< "Sign Grade: " << obj.getSignGrade() << std::endl << "Required Grade: " << obj.getRequiredGrade() << std::endl;
	return os;
}

const char* Form::getName( void ) const{
	return _name;
}

bool	Form::isSigned( void ) const{
	return _signed;
}

int		Form::getSignGrade( void ) const {
	return _signGrade;
}

int		Form::getRequiredGrade( void ) const {
	return _requiredGrade;
}

const char *Form::GradeTooHighException::what() const throw(){
	return ("Grade is too high to sign the formulary");
}

const char *Form::GradeTooLowException::what() const throw(){
	return ("Grade is too low to sign the formulary");
}

bool	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() < _signGrade) {
		_signed = 1;
		return 1;
	}
	throw Form::GradeTooLowException();
	return 0;
}

#include "Form.hpp"

Form::Form( void ) : _name("Gabriel"), _signed(0), _signGrade(0), _requiredGrade(0){
}

Form::~Form( void ){
}

Form::Form( const Form& copy ) : _name("Gabriel"), _signed(0), _signGrade(0), _requiredGrade(0){
	*this = copy;
}

Form& Form::operator=( const Form& copy ) {
	(void)copy;
	return (*this);
}

std::ostream& operator<<( std::ostream& os, Form& obj ) {
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

int		Form::getSignGrade( void ){
	return _signGrade;
}

int	Form::getRequiredGrade( void ){
	return _requiredGrade;
}

bool	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() < _requiredGrade) {
		_signed = 1;
		return 1;
	}
	throw Form::GradeTooLowException();
	return 0;
}

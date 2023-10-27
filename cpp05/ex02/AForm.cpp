#include "AForm.hpp"

AForm::AForm( void ) : _name("Dummy"), _signed(0), _signGrade(0), _requiredGrade(0){
}

AForm::~AForm( void ){
}

AForm::AForm( const AForm& copy ) : _name("Dummy"), _signed(0), _signGrade(0), _requiredGrade(0){
	*this = copy;
}

AForm::AForm( const char* name, const int signGrade, const int requiredGrade) : _name(name), _signed(0), _signGrade(signGrade), _requiredGrade(requiredGrade){
}

AForm& AForm::operator=( const AForm& copy ) {
	(void)copy;
	return (*this);
}

std::ostream& operator<<( std::ostream& os, const AForm& obj ) {
	os << "Name: "<< obj.getName() << std::endl << "Signed: " << obj.isSigned() << std::endl \
	<< "Sign Grade: " << obj.getSignGrade() << std::endl << "Required Grade: " << obj.getRequiredGrade() << std::endl;
	return os;
}

const char* AForm::getName( void ) const{
	return _name;
}

bool	AForm::isSigned( void ) const{
	return _signed;
}

int		AForm::getSignGrade( void ) const {
	return _signGrade;
}

int		AForm::getRequiredGrade( void ) const {
	return _requiredGrade;
}

const char *AForm::GradeTooHighException::what() const throw(){
	return ("Grade is too high to sign the formulary");
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("Grade is too low to sign the formulary");
}

bool	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade) {
		_signed = 1;
		return 1;
	}
	throw AForm::GradeTooLowException();
	return 0;
}

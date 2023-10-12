#include "Form.hpp"

Form::Form( void ) : _name("Gabriel"), _signed(0){
}

Form::~Form( void ){
}

Form::Form( const Form& copy ){
	*this = copy;
}

Form& Form::operator=( const Form& copy ) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _requiredGrade(copy._requiredGrade){
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
	if (_signed == 1)
		return 1;
	return 0;
}

const int	Form::getSignGrade( void ) const{
	return _signGrade;
}

const int	Form::getRequiredGrade( void ) const{
	return _requiredGrade;
}
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Tree", 145, 137) {
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : AForm() {
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy ) {
	_target = copy._target;
	_tree = copy._tree;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :  AForm("Tree", 145, 137) {
	_target = target;
	_tree ="  ___________\n"
			" /~~~~~~~~~~\\\n"
			"/~~~~~~~~~~~~\\\n"
		   "/~~~~~~o~~o~~~\\\n"
		   "|~~~~o~~~~~~~~|\n"
		   "\\~~~~~~~o~~~~/\n"
		   " \\~~~~~~~~~~/\n"
		   "  \\~~~~~~~~/\n"
			"   | |   |\n"
		    "   | |   |\n"
		    "   | |   |   O\n"
			"   0 |   |  /|\\\n"
			"     |   |   /\\\n"
		"================\n";
}

std::string 	ShrubberyCreationForm::getTarget( void ) const{
	return _target;
}

void		ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {

	if (this->isSigned()) {
		if (this->getRequiredGrade() > executor.getGrade()) {
			std::ofstream output_stream;
			std::string	output;
			output = getTarget();
			output += "_shrubbery";
			output_stream.open(output.c_str(), std::ios::out);
			if (!output_stream.is_open()) {
				std::cout << "Error opening file" << std::endl;
				return ;
			}
			output_stream << _tree;
			std::cout << "ShrubberyCreationForm executed" << std::endl;
		}
		else
			std::cout << "The Shrubbery form is signed but can't be executed" << std::endl;
	}
	else
		std::cout << "Can't execute the Shrubbery form" << std::endl;
}
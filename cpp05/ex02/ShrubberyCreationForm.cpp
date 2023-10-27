#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : _target(""), _tree("") {
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : AForm() {
	_target = copy._target;
	_tree = copy._tree;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy ) {
	*this = copy;
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
std::cout << _tree << std::endl;
}

std::string 	ShrubberyCreationForm::getTarget( void ) const{
	return _target;
}

void		ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	std::ofstream output_stream;
	std::string		output;

	output = getTarget();
	output_stream.open(output, std::ios::out);
	if (!output_stream.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	else
		std::cout << _tree << std::endl;
}
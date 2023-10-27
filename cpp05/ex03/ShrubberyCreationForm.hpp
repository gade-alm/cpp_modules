#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm { 
	private:
		std::string _target;
		std::string	_tree;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm& copy );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& copy );
		std::string	getTarget( void ) const;
		void	execute( Bureaucrat const & executor ) const;
};

#endif
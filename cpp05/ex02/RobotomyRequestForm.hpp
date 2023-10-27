#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <time.h>
#include <stdlib.h>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		~RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& copy );

		std::string	getTarget( void ) const;
		void	execute( Bureaucrat const & executor ) const;
};

#endif
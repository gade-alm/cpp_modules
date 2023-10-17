#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
//Range 1 to 150, 1 higher 150 lower
class Form;

class Bureaucrat {
	private:
		const char* _name;
		int			_grade;
	public:
		Bureaucrat( void );
		Bureaucrat ( const char* name, int grade );
		~Bureaucrat( void );
		Bureaucrat( const Bureaucrat& copy );
		Bureaucrat& operator=( const Bureaucrat& copy );
		int	incrementGrade( int value );
		int	decreaseGrade( int value );
		bool signForm( Form &form );
		const char* getName( void ) const ;
		int	getGrade( void ) const ;
	class GradeTooHighException : public std::exception{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& obj );

#endif
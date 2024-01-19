#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
//Range 1 to 150, 1 higher 150 lower
class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int				_grade;
	public:
		Bureaucrat( void );
		Bureaucrat ( std::string name, int grade );
		~Bureaucrat( void );
		Bureaucrat( const Bureaucrat& copy );
		Bureaucrat& operator=( const Bureaucrat& copy );
		int	incrementGrade( void );
		int	decreaseGrade( void );
		bool signForm( Form &form );
		const std::string &getName( void ) const ;
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
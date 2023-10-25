#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const char* _name;
		bool		_signed;
		const int	_signGrade;
		const int	_requiredGrade;
	public:
		Form( void );
		~Form( void );
		Form( const Form& copy);
		Form& operator=( const Form& copy );
		Form( const char* _name, const int _signGrade, const int _requiredGrade );
		const char* getName( void ) const;
		bool	isSigned( void ) const;
		 int	getSignGrade( void ) const ;
		 int	getRequiredGrade( void ) const ;
		bool	beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception{
		public:
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const Form& obj );

#endif
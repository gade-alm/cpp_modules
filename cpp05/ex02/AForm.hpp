#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const char* _name;
		bool		_signed;
		const int	_signGrade;
		const int	_requiredGrade;
	public:
		AForm( void );
		~AForm( void );
		AForm( const AForm& copy);
		AForm& operator=( const AForm& copy );
		AForm( const char* _name, const int _signGrade, const int _requiredGrade );
		const char* getName( void ) const;
		bool	isSigned( void ) const;
		int		getSignGrade( void ) const ;
		int		getRequiredGrade( void ) const ;
		bool	beSigned( Bureaucrat &bureaucrat );
		virtual void	execute( Bureaucrat const & executor ) const = 0;
		class GradeTooHighException : public std::exception{
		public:
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const AForm& obj );

#endif
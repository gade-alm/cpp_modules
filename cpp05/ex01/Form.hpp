#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

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
		const char* getName( void ) const;
		bool		isSigned( void ) const;
		const int	getSignGrade( void ) const;
		const int	getRequiredGrade( void ) const;
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
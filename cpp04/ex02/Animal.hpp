#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

# define RESET   "\033[0m"
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */

//constructors
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal( const Animal& obj);
		Animal& 	operator=(const Animal& obj);
		virtual ~Animal();
		virtual void	makeSound( void ) const = 0;
		std::string	getType( void ) const ;
};

#endif
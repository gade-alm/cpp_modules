#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "Animal.hpp"

class WrongCat : public Animal{ 
	public:
		//constructors
		WrongCat():
		WrongCat( const WrongCat& obj);
		WrongCat& operator=( const WrongCat& obj);

		//destructors
		~WrongCat();

		//member functions
		void	makeSound( void ) const;
};

#endif
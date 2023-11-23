#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{ 
	public:
		//constructors
		WrongCat( void );
		WrongCat( const WrongCat& obj);
		WrongCat& operator=( const WrongCat& obj);

		//destructors
		~WrongCat( void );

		//member functions
		void	makeSound( void ) const;
};

#endif
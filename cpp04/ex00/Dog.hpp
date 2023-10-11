#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public:
		//Constructor
		Dog( void );
		Dog( const Dog& obj);
		Dog& operator=( const Dog& obj);

		//Destructor
		~Dog( void );

		//Member Functions
		void	makeSound( void ) const;
};

#endif
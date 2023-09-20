#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public:
		//Constructor
		Dog();
		Dog( const Dog& obj);
		Dog& operator=( const Dog& obj);

		//Destructor
		~Dog();

		//Member Functions
		void	makeSound( void ) const;
};

#endif
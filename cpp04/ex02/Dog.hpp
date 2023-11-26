#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain* _brain;
	public:
		//Constructor
		Dog( void );
		Dog( const Dog& obj );
		Dog& operator=( const Dog& obj );

		//Destructor
		~Dog( void );

		//Member Functions
		void	makeSound( void ) const;
		void	thinking( void ) const;
		void	insertIdea( std::string idea );
};

#endif
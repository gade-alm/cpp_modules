#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
		//Constructors
		Cat();
		Cat( const Cat& obj);
		Cat& operator=( const Cat& obj);
		
		//Destructors
		~Cat();

		//member functions
		void	makeSound( void ) const;
};

#endif
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;
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
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;
	public:
		//Constructors
		Cat( void );
		Cat( const Cat& obj );
		Cat& operator=( const Cat& obj );
		
		//Destructors
		~Cat( void );

		//member functions
		void	makeSound( void ) const;
};

#endif
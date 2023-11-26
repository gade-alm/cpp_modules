#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
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
		void	thinking( void ) const;
		void	insertIdea( std::string idea );
};

#endif
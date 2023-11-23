#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;
	public:
		//constructors
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& obj );
		WrongAnimal& operator=( const WrongAnimal& obj );

		//destructors
		virtual ~WrongAnimal( void );

		//member functions
		virtual void		makeSound() const;
		std::string	getType() const;
};

#endif
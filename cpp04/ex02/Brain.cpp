#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain ( const Brain& obj ) {
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = obj;
}

Brain& Brain::operator=( const Brain& obj ) {
	std::cout << "Brain assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	return (*this);
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
}

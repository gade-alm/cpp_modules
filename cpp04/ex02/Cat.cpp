#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << YELLOW << "Cat Default Constructor Called" << RESET << std::endl;
}

Cat::~Cat() {
	std::cout << YELLOW << "Cat Default destructor called" << RESET << std::endl;
	delete _brain;
}

Cat::Cat ( const Cat& obj) :AAnimal() {
	std:: cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
	_type = "Cat";
	_brain = new Brain();
	*this = obj;
}

Cat& Cat::operator=( const Cat& obj) {
	_type = obj._type;
	std::cout << YELLOW << "Cat assignment overload called" << RESET << std::endl;
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << YELLOW << "Miau" << RESET << std::endl;
}

void	Cat::insertIdea( std::string idea ) {
	this->_brain->learnIdeas(idea);
}

void	Cat::thinking( void ) const {
	std::cout << YELLOW << "Cat is thinking: \"" << this->_brain->showIdea() << "\"" << RESET << std::endl;
}
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	AAnimal *animal = new Cat();
	animal->makeSound();
	delete animal;

	std::cout << "<----------------NEW TEST---------------->" << std::endl;
	Dog dog = Dog();
	dog.makeSound();
	dog.insertIdea("I love bones!");
	dog.thinking();

	std::cout << "<----------------NEW TEST---------------->" << std::endl;
	Cat cat = Cat();
	cat.makeSound();
	cat.insertIdea("hmmm, snacks");
	cat.thinking();
}
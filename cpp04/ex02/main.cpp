#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	Animal *animal = new Cat();
	animal->makeSound();
	delete animal;

	std::cout << "<----------------NEW TEST---------------->" << std::endl;
	Dog dog = Dog();
	dog.makeSound();

	std::cout << "<----------------NEW TEST---------------->" << std::endl;
	Cat cat = Cat();
	cat.makeSound();
}
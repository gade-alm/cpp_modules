#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	const Animal* meta = new Animal();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound(); // output no sound

	const Animal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound(); // output dog sound!

	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!

	delete i;
	delete j;
	delete meta;
	return 0;
}
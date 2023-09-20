#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
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
	}
	const WrongAnimal* wrong = new WrongAnimal();
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	const WrongAnimal* x = new WrongCat();
	std::cout << x->getType() << std::endl;
	x->makeSound();

	delete x;
	delete wrong;
}
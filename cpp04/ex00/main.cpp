#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
	{
	const Animal* meta = new Animal();
	std::cout << RED << "Type of animal is: " << meta->getType() << RESET << std::endl;
	meta->makeSound(); // output no sound

	const Animal* j = new Dog();
	std::cout << BLUE << "Type of animal is: " << j->getType() << RESET << std::endl;
	j->makeSound(); // output dog sound!

	const Animal* i = new Cat();
	std::cout << YELLOW << "Type of animal is: " << i->getType() << RESET << std::endl;
	i->makeSound(); //will output the cat sound!

	delete i;
	delete j;
	delete meta;
	}
	const WrongAnimal* wrong = new WrongAnimal();
	std::cout << CYAN << "Type of animal is: " << wrong->getType() << RESET << std::endl;
	wrong->makeSound();

	const WrongAnimal* x = new WrongCat();
	std::cout << MAGENTA << x->getType() << RESET << std::endl;
	x->makeSound();

	delete x;
	delete wrong;
}
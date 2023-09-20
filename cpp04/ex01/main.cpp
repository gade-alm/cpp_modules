#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	const Animal *animals[10];

	int i = 0;
	while (i++ < 5)
	{
		animals[i] = new Dog();
		std::cout << i << ". "; 
		animals[i]->makeSound();
	}
	while (i < 10)
	{
		animals[i] = new Cat();
		std::cout << i << ". "; 
		animals[i]->makeSound();
		i++;
	}
	for (int j = 0; j < 10; j++)
		delete animals[j];
	return 0;
}
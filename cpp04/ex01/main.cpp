#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	Dog basic;

	Dog temp = basic;

	temp.insertIdea("To com outra coisa na cabeca");
	basic.insertIdea("Testando ideias");
	basic.thinking();
	temp.thinking();

	{
	const Animal *animals[10];

	int i = 0;
	for (; i < 5; i++) {
		animals[i] = new Dog();
		std::cout << i << ". "; 
		animals[i]->makeSound();
	}
	for (; i < 10; i++) {
		animals[i] = new Cat();
		std::cout << i << ". "; 
		animals[i]->makeSound();
	}
	for (int j = 0; j < 10; j++)
		delete animals[j];
	}
}
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("Gabriel");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	}
	std::cout << "---------------------2nd Test---------------------" << std::endl;
	{/* 
		IMateriaSource* test = new MateriaSource();
		for (int i = 0; i < 3 ; i++)
			test->learnMateria(new Ice());
		AMateria* wrongMateria = NULL;
		test->learnMateria(wrongMateria);
		test->learnMateria(new Ice());
		test->learnMateria(new Ice());
		ICharacter* learner = new Character("");
		AMateria* temp;
		temp = test->createMateria("wrongMateria");
		learner	->equip(temp);
		delete learner;
		delete test; */
	}
}
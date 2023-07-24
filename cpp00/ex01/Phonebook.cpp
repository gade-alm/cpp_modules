#include "Phonebook.hpp"

Phonebook::Phonebook(){
	this->index = 0;
}

void	Phonebook::search(void)
{
	int		index;

	index = 0;
	std::cout << "|===========================================|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|===========================================|" << std::endl;
	while (index < Phonebook::index)
	{
		std::cout << "|         " << index << "|";
		std::cout << "contact123" << '|';
		std::cout << "lastname12" << '|';
		std::cout << "nickname12" << '|' << std::endl;
		std::cout << "|===========================================|" << std::endl;
		index++;
	}
}

void	Phonebook::add(void)
{
	std::string	input;
	int			i;

	i = 0;
	std::cout << "Write First Name" << std::endl;
	getline(std::cin, input);
	contacts[i].set_first(input);
	std::cout << "Write Last Name" << std::endl;
	getline(std::cin, input);
	contacts[i].set_last(input);
	std::cout << "Write Nickname" << std::endl;
	getline(std::cin, input);
	contacts[i].set_nick(input);
	std::cout << "Write Number" << std::endl;
	getline(std::cin, input);
	contacts[i].set_number(input);
	std::cout << "Write Darkest Secret" << std::endl;
	getline(std::cin, input);
	contacts[i].set_secret(input);
}

#include "Phonebook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;

	system("clear");
	while (!std::cin.eof())
	{
		std::cout << "Write a valid command(ADD, SEARCH or EXIT)" << std::endl;
		getline(std::cin, input);
		if (input == "ADD")
			phonebook.add();
		if (input == "SEARCH")
			phonebook.search();
		if (input == "EXIT")
		{
			std::cout << "You exited the phonebook" << std::endl;
			break ;
		}
		std::cin.clear();
	}
}

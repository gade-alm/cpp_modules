#include "Phonebook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;

	while (!std::cin.eof())
	{
		system("clear");
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
	}
}

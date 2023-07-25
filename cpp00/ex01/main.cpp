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
		if (input == "search")
			phonebook.search();
		if (input == "add")
			phonebook.add();
		if (input == "exit")
		{
			std::cout << "You exited the phonebook" << std::endl;
			break ;
		}
	}
}

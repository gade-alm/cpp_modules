#include "Phonebook.hpp"

Phonebook::Phonebook(){
	this->index = 0;
}

void	Phonebook::search(void)
{
	int			i;
	int			num;

	system("clear");
	i = 0;
	std::cout << "|===========================================|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|===========================================|" << std::endl;
	while (i < 8 && (check_contact(i) == true))
	{
		std::cout << '|' << std::setw(10) << i << '|';
		std::cout << std::setw(10) << contacts[i].print_name().substr(0, 9) << '|';
		std::cout << std::setw(10) << contacts[i].print_last().substr(0, 9) << '|';
		std::cout << std::setw(10) << contacts[i].print_nick().substr(0, 9) << '|' << std::endl;
		std::cout << "|===========================================|" << std::endl;
		i++;
	}
	std::cout << "Write the index of the contact you want to see:" << std::endl;
	std::cin >> num;
	if (num >= 0 && num < i && check_contact(num) == 1)
		get_info(num);
	std::cin.clear();
}

void	Phonebook::add(void)
{
	std::string	input;

	system("clear");
	if (index > 7)
		index = 0;
	std::cout << "Write First Name" << std::endl;
	getline(std::cin, input);
	contacts[index].set_first(input);

	std::cout << "Write Last Name" << std::endl;
	getline(std::cin, input);
	contacts[index].set_last(input);

	std::cout << "Write Nickname" << std::endl;
	getline(std::cin, input);
	contacts[index].set_nick(input);

	std::cout << "Write Number" << std::endl;
	getline(std::cin, input);
	contacts[index].set_number(input);

	std::cout << "Write Darkest Secret" << std::endl;
	getline(std::cin, input);
	contacts[index].set_secret(input);

	if (check_contact(index) == 0)
	{
		std::cout << "Missing contact information, try again." << std::endl;
		return ;
	}
	index++;
}

bool	Phonebook::check_contact(int number)
{
	if (contacts[number].print_name() == "" || contacts[number].print_last() == "" || \
	contacts[number].print_nick() == "" || contacts[number].print_number() == "" || \
	contacts[number].print_secret() == "")
		return (false);
	return (true);
}

void	Phonebook::get_info(int num)
{
	std::cout << "First Name:" << contacts[num].print_name() << std::endl;
	std::cout << "Last Name:" << contacts[num].print_last() << std::endl;
	std::cout << "Nickname:" << contacts[num].print_nick() << std::endl;
	std::cout << "Number:" << contacts[num].print_number() << std::endl;
	std::cout << "Darkest Secret:" << contacts[num].print_secret() << std::endl;
	std::cout << "Press enter to continue..." << std::endl;
	std::cin.ignore();
	std::cin.get();
}
#include "Phonebook.hpp"

void	Contact::set_first(std::string	first)
{
	Contact	contact;

	contact.first_name = first;
}

void	Contact::set_last(std::string	last)
{
	Contact	contact;

	contact.last_name = last;
}

void	Contact::set_nick	(std::string	nick)
{
	Contact	contact;

	contact.nickname = nick;
}

void	Contact::set_number(std::string	number)
{
	Contact	contact;

	contact.number = number;
}

void	Contact::set_secret(std::string	secret)
{
	Contact	contact;

	contact.darkest_secret = secret;
}

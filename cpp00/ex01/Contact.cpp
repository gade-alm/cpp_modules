#include "Phonebook.hpp"

void	Contact::set_first(std::string	first)
{
	this->first_name = first;
}

void	Contact::set_last(std::string	last)
{
	this->last_name = last;
}

void	Contact::set_nick	(std::string	nick)
{
	this->nickname = nick;
}

void	Contact::set_number(std::string	number)
{
	this->number = number;
}

void	Contact::set_secret(std::string	secret)
{
	this->darkest_secret = secret;
}

std::string	Contact::print_name(void)
{
	return this->first_name;
}

std::string	Contact::print_last(void)
{
	return this->last_name;
}

std::string	Contact::print_nick(void)
{
	return this->nickname;
}

std::string	Contact::print_number(void)
{
	return this->number;
}

std::string	Contact::print_secret(void)
{
	return this->darkest_secret;
}

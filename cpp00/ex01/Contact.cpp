#include "Phonebook.hpp"

void	Contact::set_first(std::string first) {
	this->_first_name = first;
}

void	Contact::set_last(std::string last) {
	this->_last_name = last;
}

void	Contact::set_nick	(std::string nick) {
	this->_nickname = nick;
}

void	Contact::set_number(std::string	number) {
	this->_number = number;
}

void	Contact::set_secret(std::string	secret) {
	this->_darkest_secret = secret;
}

std::string	Contact::print_name(void) {
	return this->_first_name;
}

std::string	Contact::print_last(void) {
	return this->_last_name;
}

std::string	Contact::print_nick(void) {
	return this->_nickname;
}

std::string	Contact::print_number(void) {
	return this->_number;
}

std::string	Contact::print_secret(void) {
	return this->_darkest_secret;
}

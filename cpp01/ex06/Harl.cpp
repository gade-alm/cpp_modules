#include "Harl.hpp"

Harl::Harl(){
	pointer[0] = &Harl::debug;
	pointer[1] = &Harl::info;
	pointer[2] = &Harl::warning;
	pointer[3] = &Harl::error;
	std::cout << "Default constructor called" << std::endl;
}

Harl::~Harl(){
	std::cout << "Default destructor called" << std::endl;
}

void	Harl::debug( void ) { 
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\
	ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) { 
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put\
	enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for\
	years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level ) {
	
	enum messages{
		DEBUG = 0,
		INFO = 1,
		WARNING = 2,
		ERROR = 3,
	}messages;

	switch (messages){
		case 0:
			std::cout << "teste" << std::endl;
			break ;
		case 1:
			std::cout << "teste" << std::endl;
			break ;
		case 2:
			std::cout << "teste" << std::endl;
			break ;
		case 3:
			std::cout << "teste" << std::endl;
			break ;
	}
}
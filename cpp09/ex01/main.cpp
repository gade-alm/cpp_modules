#include "RPN.hpp"

int main (int ac, char **av) {

	if (ac != 2) {
		std::cout << "Wrong number of parameters" << std::endl;
		return 1;
	}
	try {
		checkValues(av[1]);
		calcValue(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

#include <unistd.h>

void ft_putchar( char c) {
	write (1, &c, 1);
}
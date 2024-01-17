#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Error on parameters, please check your inputs!" << std::endl;
		return 1;
	}
	openDatabase( av[1] );
	return 0;
}
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Error on parameters, please check your inputs!" << std::endl;
		return 1;
	}
	try {
		openDatabase( av[1] );
	}
	catch ( std::exception &e ) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
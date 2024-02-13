#include "PmergeMe.hpp"

int main ( int ac, char **av ) {

	if (ac < 3) {
		std::cout << "Wrong number of parameters" << std::endl;
		return 1;
	}
	try {
		checkValues(av);
		checkDuplicates(av);

		std::vector<std::pair<int, int> >	vectorsPair;
		std::deque<std::pair<int, int> >	dequesPairs;
		std::vector<int>					vectors;
		std::deque<int>						deques;
		int									i = 1;
		std::cout << "Before: ";
		for (; av[i]; i++)
			std::cout << av[i] << " ";
		std::cout << std::endl;

		clock_t	v_init;
		clock_t	v_end;
		v_init = clock();
		pushVectorsNumbers(vectors, vectorsPair, av);
		v_end = clock() - v_init;
		std::cout << "Time to process a range of " << i << " elements with std::vector " << ((float)v_end)/CLOCKS_PER_SEC << " us" << std::endl;
		// std::cout << "<--------TESTE PAIRS SORTED WITH RECURSION-------->" << std::endl;
		//Deques part
		clock_t d_init;
		clock_t d_end;
		d_init = clock();
		pushDequeNumbers(deques, dequesPairs, av);
		d_end = clock() - d_init;
		std::cout << "Time to process a range of " << i << " elements with std::deque " << ((float)d_end)/CLOCKS_PER_SEC << " us" << std::endl;
	}
	catch ( std::exception &e ){
		std::cerr << e.what() << std::endl;
	}
	return 1;
}

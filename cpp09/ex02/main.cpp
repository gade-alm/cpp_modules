#include "PmergeMe.hpp"

int main ( int ac, char **av ) {

	if (ac < 2) {
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

		pushVectorsNumbers(vectors, vectorsPair, av);
		// std::cout << "<--------TESTE PAIRS SORTED WITH RECURSION-------->" << std::endl;
		// printPair(vectorsPair);
		//Deques part
		// pushDequeNumbers(deques, dequesPairs, av);
	}
	catch ( std::exception &e ){
		std::cerr << e.what() << std::endl;
	}
	return 1;
}

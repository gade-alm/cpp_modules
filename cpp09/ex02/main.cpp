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

		//Insert values on vectorPairs and sort them to stay larger value first in each pair (steps 1 and 2 in wikipedia)
		pushVectorsNumbers(vectors, vectorsPair, av);
		//Recursively sort the values in the vector pairs
		recursiveSort( vectorsPair, vectorsPair.size() - 1);
		std::cout << "TESTE PAIRS" << std::endl;
		printPair(vectorsPair);

		//Deques part
		pushDequeNumbers( deques, dequesPairs, av );
	}
	catch ( std::exception &e ){
		std::cerr << e.what() << std::endl;
	}
	return 1;
}
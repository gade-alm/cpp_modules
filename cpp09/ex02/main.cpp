#include "PmergeMe.hpp"

int main ( int ac, char **av ) {

	if (ac < 2) {
		std::cout << "Wrong number of parameters" << std::endl;
		return 1;
	}
	try {
		checkValues(av);
		checkDuplicates(av);

		const std::clock_t v_start = std::clock();
		std::vector<int> vectors;
		pushVectorsNumbers(vectors, av);

		std::cout << "Before: ";
		print(vectors);
		mergeNumbersVector(vectors);
		std::cout << "After: ";
		print(vectors);
		const std::clock_t v_end = std::clock();
		std::cout << std::fixed << std::setprecision(4) << "Time to process a range of " << vectors.size() << " elements with std::vector: " << static_cast<double>((v_end - v_start))/ CLOCKS_PER_SEC << "us" << std::endl;

	}
	catch ( std::exception &e ){
		std::cerr << e.what() << std::endl;
	}
	return 1;
}
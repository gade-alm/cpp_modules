#include "PmergeMe.hpp"

//`shuf -i 1-100000 -n 30000 | tr "\n" " " `

void print(std::vector<int> &vec){

	std::vector<int>::iterator itv = vec.begin();

	for(; itv != vec.end(); itv++){
		std::cout << *itv << " ";
	}
	std::cout << std::endl;
}

void	checkValues( char** string ) {

	for (size_t i = 1; string[i]; i++) {
		for (size_t j = 0; string[i][j]; j++)
			if ((!isdigit(string[i][j])) && string[i][j] != ' ')
				throw std::out_of_range("Wrong input values");
	}
	return ;
}

void	pushVectorsNumbers( std::vector<int> &vectors, char** av) {
	int temp = 0;

	for (size_t i = 1; av[i]; i++) {
		temp = atoi(av[i]);
		if (temp < 0 || temp > 2147483647)
			throw std::out_of_range("Int overflow or less than 0");
		vectors.push_back(temp);
	}
	return ;
}

void	checkDuplicates( char **string ) {

	int		value = 0;

	for (size_t i = 1; string[i]; i++) {
		value = atoi(string[i]);
		for (size_t j = i + 1; string[j]; j++) {
			if (atoi(string[j]) == value)
				throw std::out_of_range("Duplicate values");
		}
	}
}

void	mergeNumbersVector( std::vector<int> &vectors ) {

	if (vectors.size() <= 3) {
		insertionNumbersVector(vectors);
		return ;
	}
	int mid = vectors.size() / 2;
	std::vector<int> leftSide(vectors.begin(), vectors.begin() + mid);
	std::vector<int> rightSide(vectors.begin() + mid, vectors.end());

	mergeNumbersVector(leftSide);
	mergeNumbersVector(rightSide);

	merge(leftSide.begin(),leftSide.end(), rightSide.begin(),rightSide.end(), vectors.begin());
}

void	insertionNumbersVector( std::vector<int> &vectors ) {

	std::vector<int>::iterator it =	vectors.begin();
	std::vector<int>::iterator copy;
	int								key = 0;

	for (; it != vectors.end() - 1; it++) {
		if (*it > *(it + 1)) {
			key = *it;
			*it = *(it + 1);
			*(it +1) = key;
		}
	}
}

// void	mergeNumbersList( std::list<int> &lists ) {
	
// 	if (lists.size() < 2)
// 		return ;
// 	int mid = lists.size() / 2;

// 	std::list<int> leftSide(lists.begin(), lists.begin());
// 	std::list<int> rightSide(lists.begin(), lists.end());
// }
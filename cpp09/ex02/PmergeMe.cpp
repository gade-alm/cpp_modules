#include "PmergeMe.hpp"

//`shuf -i 1-100000 -n 30000 | tr "\n" " " `

void print(std::vector<int> &vec){

	std::vector<int>::iterator itv = vec.begin();

	for(; itv != vec.end(); itv++){
		std::cout << *itv << " ";
	}
	std::cout << std::endl;
}

void printPair(std::vector<std::pair<int, int> > &vec){

	std::vector<std::pair<int, int> >::iterator itv = vec.begin();

	for(; itv != vec.end(); itv++){
		std::cout << "a: " << itv->first << " b: " << itv->second << " ";
		std::cout << std::endl;
	}
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

void	checkValues( char** string ) {

	for (size_t i = 1; string[i]; i++) {
		for (size_t j = 0; string[i][j]; j++)
			if ((!isdigit(string[i][j])) && string[i][j] != ' ')
				throw std::out_of_range("Wrong input values");
	}
	return ;
}

void	pushVectorsNumbers( std::vector<int> &vectors, std::vector<std::pair<int,int> > &vectorsPair, char** av) {

	int	i = 1;
	int	temp = 0;

	for (; av[i]; i++) {
		temp = atoi(av[i]);
		if (temp < 0 || temp > 2147483647)
			throw std::out_of_range("Number negative or overflow");
		vectors.push_back(temp);
	}
	if (vectors.size() % 2 != 0) {
		temp = vectors.back();
		vectors.pop_back();
	}
	
	//Create vector pairs after checking if the size is even
	std::vector<int>::iterator	it = vectors.begin();
	for (; it != vectors.end(); it += 2) {
		vectorsPair.push_back(std::pair<int, int>(*it, *(it + 1)));
	}
	std::cout << "<----------VALUES ON VECTOR PAIRS---------->" << std::endl;
	printPair(vectorsPair);

	//Swaping values to make the bigger value stay first
	std::vector<std::pair<int, int> >::iterator itPair = vectorsPair.begin();
	for (; itPair != vectorsPair.end(); itPair++) {
		if (itPair->second > itPair->first)
			std::swap(itPair->second, itPair->first);
	}
	std::cout << "<----------VECTOR PAIRS SORTED BY HIGHEST FIRST--------->" << std::endl;
	printPair(vectorsPair);
	recursiveSort( vectorsPair, vectorsPair.size() - 1);
	insertionVectorsSort( vectorsPair );
	return ;
}

void	recursiveSort( std::vector<std::pair<int, int> > &vectorPairs, int size ) {
	if (size < 1)
		return ;
	int tempSize = size;
	static bool checker = 0;
	std::vector<std::pair<int, int> >::iterator itPair = vectorPairs.begin();

	for (; size > 0; size--) {
		if (itPair[size - 1].first > (itPair)[size].first) {
			std::swap(itPair[size - 1], itPair[size]);
		}
	}
	if (tempSize == 1 && checker == 0) {
		tempSize = vectorPairs.size();
		checker = 1;
	}
	recursiveSort( vectorPairs, tempSize - 1);
}

// std::vector<int> &insertionVectorsSort( std::vector<std::pair<int, int> > &vectorPairs){
// 	std::vector<int> mainChain;

// 	mainChain.push_back(vectorPairs[0].second);
// 	std::vector<std::pair<int, int> >::iterator it = vectorPairs.begin();
// 	for(; it != vectorPairs.end(); it++)
// 		mainChain.push_back(vectorPairs[0].first);
// 	(void)vectorPairs;
// }

//<-------------------------------------------DEQUES PART------------------------------------------->

void	pushDequeNumbers( std::deque<int> &deques, std::deque<std::pair<int, int> > &dequesPair, char** av ){

	int i = 0;
	int temp = 0;

	for (; av[i]; i++) {
		temp = atoi(av[i]);
		if (temp < 0 || temp > 2147483647)
			throw std::out_of_range("Number negative or overflow");
		deques.push_back(temp);
	}
	if (deques.size() % 2 != 0) {
		temp = deques.back();
		deques.pop_back();
	}
	std::deque<int>::iterator	it = deques.begin();
	for (; it != deques.end(); it += 2) {
		dequesPair.push_back(std::pair<int, int>(*it, *(it + 1)));
	}

	std::deque<std::pair<int, int> >::iterator itPair = dequesPair.begin();
	for (; itPair != dequesPair.end(); itPair++) {
		if (itPair->second > itPair->first)
			std::swap(itPair->second, itPair->first);
	}
}
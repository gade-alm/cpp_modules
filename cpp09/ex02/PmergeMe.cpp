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

	int		i = 1;
	int		temp = 0;
	bool	odd;

	std::vector<int> bigChain;

	for (; av[i]; i++) {
		temp = atoi(av[i]);
		if (temp < 0 || temp > 2147483647)
			throw std::out_of_range("Number negative or overflow");
		vectors.push_back(temp);
	}
	if (vectors.size() % 2 != 0) {
		temp = vectors.back();
		vectors.pop_back();
		odd = 1;
	}
	
	//Create vector pairs after checking if the size is even
	std::vector<int>::iterator	it = vectors.begin();
	for (; it != vectors.end(); it += 2) {
		vectorsPair.push_back(std::pair<int, int>(*it, *(it + 1)));
	}
	// std::cout << "<----------VALUES ON VECTOR PAIRS---------->" << std::endl;
	// printPair(vectorsPair);

	//Swaping values to make the bigger value stay first
	std::vector<std::pair<int, int> >::iterator itPair = vectorsPair.begin();
	for (; itPair != vectorsPair.end(); itPair++) {
		if (itPair->second > itPair->first)
			std::swap(itPair->second, itPair->first);
	}
	std::cout << "<----------VECTOR PAIRS SORTED BY HIGHEST FIRST--------->" << std::endl;
	printPair(vectorsPair);
	recursiveSort( vectorsPair, 0 );
	bigChain = mainChain( vectorsPair );
	if (odd)
		bigChain.push_back(temp);
	std::cout << "BIG CHAIN PRINTING" << std::endl;
	print(bigChain);
	return ;
}

void	recursiveSort( std::vector<std::pair<int, int> > &vectorPairs, size_t size ) {
	if (size == vectorPairs.size())
		return ;
	
	for (size_t i = 0; i < vectorPairs.size() - 1; i++) {
		if (vectorPairs[i].first > vectorPairs[size].first) {
			std::swap(vectorPairs[i], vectorPairs[size]);
		}
	}
	recursiveSort( vectorPairs, ++size );
}

std::vector<int> mainChain( std::vector<std::pair<int, int> > &vectorPairs ) {
	
	std::vector<int> mainVector;
	std::vector<std::pair<int, int> >::iterator itp = vectorPairs.begin();

	mainVector.push_back(itp->second);
	for (; itp != vectorPairs.end(); itp++) {
		mainVector.push_back(itp->first);
	}
	return mainVector;
}

/* void	insertionVectorsSort( std::vector<std::pair<int, int> > &vectorPairs, std::vector<int> &vectors ){
	long jacobsthal[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 
	1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 
	1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 
	178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

	std::vector<int> testing;
	int		temp = 0;
	if (vectors.size() % 2 != 0) {
		temp = vectors.back();
		vectors.pop_back();
	}

	int i = 0;
	while (jacobsthal[i] < vectorPairs.size() - 1)
	for (size_t i = 0; jacobsthal[i] && i < vectorPairs.size(); i++) {
		testing.push_back(jacobsthal[i]);
	}
	std::vector<int>::iterator test = testing.begin();
	for (; test != testing.end(); test++)
		std::cout << *test << std::endl;
}
 */
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
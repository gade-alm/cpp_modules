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
	bool	odd = 0;

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

	//Swaping values to make the bigger value stay first
	std::vector<std::pair<int, int> >::iterator itPair = vectorsPair.begin();
	for (; itPair != vectorsPair.end(); itPair++) {
		if (itPair->second > itPair->first)
			std::swap(itPair->second, itPair->first);
	}

	recursiveSort( vectorsPair, 0 );
	bigChain = mainChainVector( vectorsPair );
	if (odd)
		vectorsPair.push_back(std::pair<int, int>(0, temp));

	std::vector<int>::iterator b_it;
	std::vector<int> sequence = insertionVectorsSort( vectorsPair );
	std::vector<int>::iterator s_it = sequence.begin();

	for (; s_it != sequence.end(); s_it++) {
		b_it = bigChain.begin();
		while (*b_it < vectorsPair[*s_it - 1].second){
			b_it++;
		}
		bigChain.insert(b_it, vectorsPair[*s_it - 1].second);
		
	}
	// print(bigChain);
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

std::vector<int> mainChainVector( std::vector<std::pair<int, int> > &vectorPairs ) {
	
	std::vector<int> mainVector;
	std::vector<std::pair<int, int> >::iterator itp = vectorPairs.begin();

	mainVector.push_back(itp->second);
	for (; itp != vectorPairs.end(); itp++) {
		mainVector.push_back(itp->first);
	}
	return mainVector;
}

std::vector<int>	insertionVectorsSort( std::vector<std::pair<int, int> > &vectorPairs ){
	long jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 
	1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 
	1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 
	178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

	int	checkerIndex = vectorPairs.size();
	int	i = 0;
	long temp = 0;
	std::vector<int> sequence;

	while (checkerIndex > jacobsthal[i])
		i++;
	if (i == 0)
		return sequence;
	for (int j = 0; j < i; j++) {
		temp = jacobsthal[j + 1];
		if (checkerIndex < temp)
			temp = checkerIndex;
		while (temp > jacobsthal[j]) {
			sequence.push_back(temp);
			temp--;
		}
	}
	return sequence;
}

//<-------------------------------------------DEQUES PART------------------------------------------->

void	pushDequeNumbers( std::deque<int> &deques, std::deque<std::pair<int, int> > &dequesPair, char** av ){

	int		i = 1;
	int		temp = 0;
	bool	odd = 0;

	std::deque<int> bigChain;

	for (; av[i]; i++) {
		temp = atoi(av[i]);
		if (temp < 0 || temp > 2147483647)
			throw std::out_of_range("Number negative or overflow");
		deques.push_back(temp);
	}
	if (deques.size() % 2 != 0) {
		temp = deques.back();
		deques.pop_back();
		odd = 1;
	}
	
	//Create vector pairs after checking if the size is even
	std::deque<int>::iterator	it = deques.begin();
	for (; it != deques.end(); it += 2) {
		dequesPair.push_back(std::pair<int, int>(*it, *(it + 1)));
	}

	//Swaping values to make the bigger value stay first
	std::deque<std::pair<int, int> >::iterator itPair = dequesPair.begin();
	for (; itPair != dequesPair.end(); itPair++) {
		if (itPair->second > itPair->first)
			std::swap(itPair->second, itPair->first);
	}

	recursiveSort( dequesPair, 0 );

	bigChain = mainChainDeque( dequesPair );
	if (odd)
		dequesPair.push_back(std::pair<int, int>(0, temp));

	std::deque<int>::iterator b_it;
	std::deque<int> sequence = insertionDequesSort( dequesPair );
	std::deque<int>::iterator s_it = sequence.begin();

	for (; s_it != sequence.end(); s_it++) {
		b_it = bigChain.begin();
		while (*b_it < dequesPair[*s_it - 1].second){
			b_it++;
		}
		bigChain.insert(b_it, dequesPair[*s_it - 1].second);
		
	}
	return ;
}

void	recursiveSort( std::deque<std::pair<int, int> > &dequesPairs, size_t size ) {
	if (size == dequesPairs.size())
		return ;
	
	for (size_t i = 0; i < dequesPairs.size() - 1; i++) {
		if (dequesPairs[i].first > dequesPairs[size].first) {
			std::swap(dequesPairs[i], dequesPairs[size]);
		}
	}
	recursiveSort( dequesPairs, ++size );
}


std::deque<int> mainChainDeque( std::deque<std::pair<int, int> > &dequesPairs ) {
	
	std::deque<int> maindeque;
	std::deque<std::pair<int, int> >::iterator itp = dequesPairs.begin();

	maindeque.push_back(itp->second);
	for (; itp != dequesPairs.end(); itp++) {
		maindeque.push_back(itp->first);
	}
	return maindeque;
}

std::deque<int>	insertionDequesSort( std::deque<std::pair<int, int> > &dequesPairs ){
	long jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 
	1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 
	1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 
	178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

	int	checkerIndex = dequesPairs.size();
	int	i = 0;
	long temp = 0;
	std::deque<int> sequence;

	while (checkerIndex > jacobsthal[i])
		i++;
	if (i == 0)
		return sequence;
	for (int j = 0; j < i; j++) {
		temp = jacobsthal[j + 1];
		if (checkerIndex < temp)
			temp = checkerIndex;
		while (temp > jacobsthal[j]) {
			sequence.push_back(temp);
			temp--;
		}
	}
	return sequence;
}

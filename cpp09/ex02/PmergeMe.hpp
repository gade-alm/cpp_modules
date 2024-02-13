#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <iomanip>

void				checkValues( char** string );
void				checkDuplicates( char** string );
void				print(std::vector<int> &vec);
void				printPair( std::vector<std::pair<int, int> > &vec );

void				pushVectorsNumbers( std::vector<int> &vectors, std::vector<std::pair<int, int> > &vectorsPair, char** av );
void				recursiveSort( std::vector<std::pair<int, int> > &vectorPairs, size_t size );
std::vector<int>	insertionVectorsSort( std::vector<std::pair<int, int> > &vectorPairs );
std::vector<int>	mainChainVector( std::vector<std::pair<int, int> > &vectorPairs );

void				pushDequeNumbers( std::deque<int> &deques, std::deque<std::pair<int, int> > &dequesPair, char** av );
void				recursiveSort( std::deque<std::pair<int, int> > &dequesPairs, size_t size );
std::deque<int>		mainChainDeque( std::deque<std::pair<int, int> > &dequesPairs );
std::deque<int>		insertionDequesSort( std::deque<std::pair<int, int> > &dequesPairs );


#endif

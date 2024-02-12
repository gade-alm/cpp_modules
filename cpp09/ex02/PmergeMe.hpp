#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>
#include <cmath>
#include <iomanip>

void				checkValues( char** string );
void				checkDuplicates( char** string );
void				print(std::vector<int> &vec);
void				pushVectorsNumbers( std::vector<int> &vectors, std::vector<std::pair<int, int> > &vectorsPair, char** av );
void				printPair( std::vector<std::pair<int, int> > &vec );
void				recursiveSort( std::vector<std::pair<int, int> > &vectorPairs, size_t size );
void				insertionVectorsSort( std::vector<std::pair<int, int> > &vectorPairs, std::vector<int> &vectors );
std::vector<int>	mainChain( std::vector<std::pair<int, int> > &vectorPairs );

void		pushDequeNumbers( std::deque<int> &deques, std::deque<std::pair<int, int> > &dequesPair, char** av );

// void		mergeNumbersList( std::list<int> &lists );

#endif

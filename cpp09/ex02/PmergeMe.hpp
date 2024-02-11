#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>
#include <iomanip>

void		checkValues( char** string );
void		checkDuplicates( char** string );
void		print(std::vector<int> &vec);
void		pushVectorsNumbers( std::vector<int> &vectors, std::vector<std::pair<int, int> > &vectorsPair, char** av );
void		printPair( std::vector<std::pair<int, int> > &vec );
void		recursiveSort( std::vector<std::pair<int, int> > &vectorPairs, int size );

void		pushDequeNumbers( std::deque<int> &deques, std::deque<std::pair<int, int> > &dequesPair, char** av );

// void		mergeNumbersList( std::list<int> &lists );

#endif

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <ctime>
#include <iomanip>

void		checkValues( char** string );
void		checkDuplicates( char** string );
void		print(std::vector<int> &vec);
void		pushVectorsNumbers( std::vector<int> &vectors, char** av );
void		mergeNumbersVector( std::vector<int> &vectors );
void		insertionNumbersVector( std::vector<int> &vectors );

// void		mergeNumbersList( std::list<int> &lists );

#endif

#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

class Span{ 
	private:
		unsigned int N;
		std::vector<int> array;
	public:
		Span( void );
		Span( unsigned int N );
		Span( const Span& copy );
		Span& operator=( const Span& copy );
		~Span( void );

		void	addNumber( int number );
		int		shortestSpan( void );
		int		longestSpan( void );
		void	showNumbers( void );
		void	addRange( unsigned int quantity );
		int		arraySize( void );
};

#endif
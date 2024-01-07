#include "Span.hpp"

int main( void ) {

	try{
		Span sp = Span(1000);

		sp.addRange(999);
		std::cout << sp.arraySize() << std::endl;
	// sp.showNumbers();
		std::cout << "Shortest difference: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest difference: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
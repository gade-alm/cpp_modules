#include "Span.hpp"

int main( void ) {

	{
		try{
			Span sp = Span(10);
			
			for (int i = 0; i < 1; i++)
				sp.addNumber(i);
			std::cout << sp.arraySize() << std::endl;
			sp.showNumbers();
			std::cout << "Shortest difference: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest difference: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			std::vector<int> values(30);
			Span sp2 = Span(29);

			std::srand(std::time(NULL));
			std::generate(values.begin(), values.end(), std::rand);
			sp2.addRange(values.begin(), values.end(), values.size());
			sp2.showNumbers();

			// std::cout << sp2.arraySize() << std::endl;
			std::cout << "Shortest difference: " << sp2.shortestSpan() << std::endl;
			std::cout << "Longest difference: " << sp2.longestSpan() << std::endl;
			}
		catch ( std::exception &e ) {
			std::cerr << e.what() << std::endl;
		}
	}
}
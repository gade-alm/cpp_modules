#include "iter.hpp"

template <typename T>
void	print(T x) {
	std::cout << x << std::endl;
}

int main ( void ) {

	int a[] = {1, 2, 3, 4};

	::iter(a, 4, print);

	std::cout << "<--------------NEW TEST-------------->" << std::endl; 
	char b[] = {'a','b','c','d'};

	::iter(b, 4, print);
	std::cout << "<--------------NEW TEST-------------->" << std::endl; 
	std::string c[] = {"Hello", "World", "42"};

	::iter(c, 3, print);
}
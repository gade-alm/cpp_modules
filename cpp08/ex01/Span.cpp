#include "Span.hpp"

Span::Span( void ) {
	this->N = 0;
}

Span::Span( unsigned int N ) {
	this->N = N;
}

Span::Span( const Span& copy ) {
	*this = copy;
}

Span& Span::operator=( const Span& copy ) {
	this->N = copy.N;
	this->array = copy.array;
	return *this;
}

Span::~Span( void ){
}

void	Span::addNumber( int number ) {
	if (array.size() < N) 
		array.push_back(number);
	else
		throw std::out_of_range("Out of bounds");
}

int		Span::shortestSpan( void ) {
	if (N < 1 || array.size() < 2)
		throw std::out_of_range("Wrong size");
	else {
		int ret = INT_MAX;

		std::sort(array.begin(), array.end());
		for (unsigned int i = 0; i < array.size() - 1; i++){
			ret = std::min(ret, array[i + 1] - array[i]);
		}
		return ret;
	}
}

int		Span::longestSpan( void ) {
	if (N < 1 || array.size() < 2)
		throw std::out_of_range("Wrong size");
	else {
		int ret = INT_MIN;

		std::sort(array.begin(), array.end());
		for (unsigned int i = 0; i < array.size() - 1; i++){
			ret = std::max(ret, array[array.size() - 1] - array[0]);
		}
		return ret;
	}
}

void	Span::showNumbers( void ) {
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << std::endl;

}

void	Span::addRange( unsigned int quantity ) {
	if (quantity > N)
		throw std::out_of_range("Quantity above N");
	else
		for (unsigned int i = 0;i < quantity; i++) {
			array.push_back(i);
		}
}

int		Span::arraySize( void ) {
	return array.size();
}
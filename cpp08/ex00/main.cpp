#include "easyfind.hpp"

int main( void ) {
	std::vector<int> values;

	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);

	easyfind(values, 4);
	easyfind(values, 0);
}
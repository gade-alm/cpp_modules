#include "easyfind.hpp"

int main( void ) {

	{
		std::cout << "----------TEST VECTOR----------" <<std::endl << std::endl;
		std::vector<int> values;

		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		values.push_back(4);

		easyfind(values, 4);
		easyfind(values, 0);
	}
	{
		std::cout << std::endl << "----------TEST LISTS----------" << std::endl << std::endl;
		std::list<int> values;

		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		values.push_back(4);

		easyfind(values, 4);
		easyfind(values, 0);
	}
	{
		std::cout << std::endl << "----------TEST DEQUE----------" <<std::endl << std::endl;
		std::deque<int> values;

		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		values.push_back(4);

		easyfind(values, 4);
		easyfind(values, 0);
		std::cout << std::endl;
	}
}
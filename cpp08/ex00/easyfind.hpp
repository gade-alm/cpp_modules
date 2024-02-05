#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>


template<typename T>
int	easyfind(T parameter, int value) {

	typename T::iterator it;

	it = std::find(parameter.begin(),parameter.end(), value);
	if (it != parameter.end()) {
		std::cout << "Value found" << std::endl;
		return 1;
	}
	else
		std::cout << "Could not find the value on the list" << std::endl;
	return 0;
}

#endif
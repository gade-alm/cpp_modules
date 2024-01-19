#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	iter( T *array , size_t length, void (*function)(const T)) {
	
	if (array == NULL || length <= 0)
		return ;
	for (size_t i = 0; i < length; i++) {
		function(array[i]);
	}
}

template <typename T>
void	print(T x) {
	std::cout << x << std::endl;
}



#endif
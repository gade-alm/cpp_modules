#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>

void	iter( T &array , size_t length, void(&T)(size_t size)) {
	while (size < length) {
		size++;
	}
}

#endif
#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <cstdlib>

template<class T> 
Array<T>::Array( void ) {
	_array = new T[0];
}

template<class T>
Array<T>::Array( unsigned int n ) {
	_arrayLength = n;
	_array = new T[n];
}

template<class T>
Array<T>::Array( const Array& copy ) {
	_array = new T[copy._arrayLength];
	_arrayLength = copy._arrayLength;
	for (size_t i = 0; i < _arrayLength; i++)
		_array[i] = copy._array[i];
}

template<class T>
Array<T>& Array<T>::operator=( const Array& copy ) {
	if (_array)
		delete []_array;
	_arrayLength = copy._arrayLength;
	_array = new T[copy._arrayLength];
	for (unsigned long i = 0; i < _arrayLength ; i++)
		_array[i] = copy._array[i];
	return (*this);
}

template<class T>
Array<T>::~Array( void ) {
	delete []_array;
}

template<class T>
const char* Array<T>::OutOfBounds::what() const throw() {
	return ("The value is out of bounds!");
}

template<class T>
T& Array<T>::operator[]( unsigned int value ) {
	if (value >= this->arraysize()) {
		throw OutOfBounds();
	}
	return _array[value];
}

template<class T>
unsigned int Array<T>::arraysize( void ) {
	return this->_arrayLength;
}

#include "Array.hpp"

#endif

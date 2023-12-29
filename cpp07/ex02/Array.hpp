#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template<class T>
class Array { 
	private:
		T* _array;
		unsigned int _arrayLength;
	public:
		Array( void );
		Array( unsigned int n );
		Array( const Array& copy );
		Array& operator=( const Array& copy );
		T& operator[]( unsigned int value );
		unsigned int arraysize( void );
		~Array( void );
	class OutOfBounds : public std::exception {
		public:
			const char *what() const throw();
	};
};

#include "Array.tpp"

#endif
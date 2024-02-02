#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <stack>
#include <iostream>
#include <iterator>
#include <list>

template< typename T >
class MutantStack : public std::stack<T> {
	private:
	public:
		MutantStack( void );
		MutantStack( const MutantStack& copy );
		MutantStack& operator=( const MutantStack& copy );
		~MutantStack( void );
		typedef typename std::deque<T>::iterator iterator;
		iterator begin( void );
		iterator end( void );
};

template<typename T>
MutantStack<T>::MutantStack( void ) {
}

template<typename T>
MutantStack<T>::MutantStack( const MutantStack& copy ) {	
	*this = copy;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack& copy ){
	(void)copy;
}

template<typename T>
MutantStack<T>::~MutantStack( void ){
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
		return this->c.begin();	
}

template<typename T>
typename	MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return this->c.end();
}

#endif
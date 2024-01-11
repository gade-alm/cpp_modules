#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
#include <stack>
#include <iostream>
#include <iterator>
#include <list>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	private:
	public:
		MutantStack( void );
		MutantStack( const MutantStack& copy );
		MutantStack& operator=( const MutantStack& copy );
		~MutantStack( void );
		typedef typename Container::iterator iterator;
		iterator begin( void );
		iterator end( void );
};

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack( void ) {
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack( const MutantStack& copy ) {	
	*this = copy;
}

template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=( const MutantStack& copy ){
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack( void ){
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin( void ) {
		return this->c.begin();	
}

template<typename T, typename Container>
typename	MutantStack<T,Container>::iterator	MutantStack<T, Container>::end( void ) {
	return this->c.end();
}

#endif
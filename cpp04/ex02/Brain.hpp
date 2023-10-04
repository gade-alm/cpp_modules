#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	protected:
		std::string ideas[100];
	public:
		//Constructors
		Brain ();
		Brain ( const Brain& obj);
		Brain& operator=( const Brain& obj);

		//destructors
		~Brain();

};

#endif
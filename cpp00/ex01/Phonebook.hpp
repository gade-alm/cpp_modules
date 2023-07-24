#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string.h>
#include <cstdlib>

class	Phonebook{
	private:
		int		index;
		Contact contacts[8];
	public:
		Phonebook();
		void	search(void);
		void	add(void);
};

#endif
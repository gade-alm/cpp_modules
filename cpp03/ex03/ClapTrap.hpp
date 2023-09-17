#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

# define RESET   "\033[0m"
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */

//constructors
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */

class ClapTrap { 
	protected:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
	public:
		ClapTrap();
		ClapTrap ( const ClapTrap& obj );
		ClapTrap& operator=( const ClapTrap& obj );
		~ClapTrap();
		ClapTrap ( std::string name );

		void				attack( const std::string& target );
		void				takeDamage( unsigned int amount );
		void				beRepaired( unsigned int amount );
};

#endif
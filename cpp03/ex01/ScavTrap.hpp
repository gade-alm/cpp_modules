#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap { 
	private:

	public:
		void	attack( const std::string& target);
};

#endif
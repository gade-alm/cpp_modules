#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap { 
	private:
		bool _guardGate;
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& obj );
		ScavTrap& operator=( const ScavTrap& obj );
		void	guardGate();
};

#endif
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap { 
	private:
		bool _guardGate;
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& obj );
		ScavTrap& operator=( const ScavTrap& obj );
		~ScavTrap( void );
		void	guardGate( void );
		void	attack( const std::string& target );
};

#endif
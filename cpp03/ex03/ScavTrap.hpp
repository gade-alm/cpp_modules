#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap { 
	private:
		bool _guardGate;
	public:
		ScavTrap( void );
		~ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& obj );
		ScavTrap& operator=( const ScavTrap& obj );
		void	guardGate( void );
		void	attack( const std::string& target );
};

#endif
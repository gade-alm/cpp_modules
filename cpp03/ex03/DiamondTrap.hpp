#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap (const DiamondTrap& obj);
		DiamondTrap& operator=( const DiamondTrap& obj);
		DiamondTrap ( std::string name );
		~DiamondTrap();
		void	whoAmI();
};

#endif
#include <string>
#include <iostream>

class HumanB{
	private:
		std::string	_name;
		std::string _weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon(std::string weapon);
};
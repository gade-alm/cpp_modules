#include <string>

class HumanA{
	private:
		std::string	_name;
		std::string _weapon;
	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		void	attack();
};
#include <string>

class Weapon{
	private:
		std::string	_type;
	public:
		Weapon(std::string weapon);
		~Weapon();
		std::string getType();
		std::string setType(std::string new_weapon);
};
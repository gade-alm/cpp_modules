#include "File.hpp"

std::string	subst_string(std::string s1, std::string s2, std::string newvar) {
	int	i = -1;
	while (newvar[++i]) {
		if (!newvar.compare(i, s1.length(), s1))
		{
			newvar.erase(i, s1.length());
			newvar.insert(i, s2);
		}
	}
	return (newvar);
}

int main(int ac, char **av) { 
	std::ifstream	source;
	std::ofstream	destiny;
	std::string		checker;
	std::string		output;
	std::string		data = av[2];
	std::string		newvar;

	if (ac != 4){ // Check if there are valid number of arguments as the exercise asks
		std::cout << "Wrong number of arguments!" << std::endl;
		return 0;
	}
	source.open(av[1]); // Open the first parameter if its a valid file, else will return an error
	if (!source.is_open()) { 
		std::cout << "Error on opening file" << std::endl;
		return 0;
	}
	output = av[1];
	output += ".replace";
	destiny.open(output.c_str(), std::ios::out); // Try to create the output file so I can write the new text
	if (!destiny.is_open()) {
		std::cout << "Error on creating file" << std::endl;
		return 0;
	}
	while (getline(source,checker))
		newvar += checker + '\n';
	newvar = subst_string(av[2], av[3], newvar);
	destiny << newvar;
	source.close();
	destiny.close();
}
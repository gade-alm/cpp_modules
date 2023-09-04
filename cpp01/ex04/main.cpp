#include "File.hpp"


int main(int ac, char **av) { 
	std::ifstream	source;
	std::ofstream	destiny;
	std::string		checker;
	std::string		output;

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
	while (!source.eof())
	{
		while (getline(source, checker))
		{
			if (checker == av[2])
			{
				
			}
		}
	}
	source.close();
	destiny.close();
}
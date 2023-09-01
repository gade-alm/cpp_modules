#include "File.hpp"

int main(void) { 
	std::fstream filename;

	filename.open("file.txt", std::ios::out); // Creates a file with first parameter as the name
	if (!filename) { 
		std::cout << "Error on creating file" << std::endl;
	}
	else {
		
		while (1)
		std::cout << "File created!" << std::endl;
		filename.close();
	}
	std::cout << "Testing" << std::endl;
}
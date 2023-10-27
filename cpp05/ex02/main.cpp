#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {
	try {
		ShrubberyCreationForm plant("Gabriel");
		Bureaucrat			bureau("Henrique", 135);
		bureau.signForm(plant);
		plant.execute(bureau);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

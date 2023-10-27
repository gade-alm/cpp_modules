#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {
	ShrubberyCreationForm plant("Gabriel");
	Bureaucrat			buro("Henrique", 1);
	plant.execute(buro);
}

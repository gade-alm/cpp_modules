#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base*	generate( void ) {

	srand(time(NULL));
	int random = rand() % 3;
	if (random == 1)
		return new A();
	else if (random == 2)
		return new B();
	else
		return new C();
}

void	identify( Base* p ) {
	if (dynamic_cast<A*>(p))
		std::cout << "Identified as A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified as B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified as C" << std::endl;
}

void	identify( Base& p ) {
	try {
		A& baseA = dynamic_cast<A&>(p);
		(void)baseA;
		std::cout << "Referenced as A" << std::endl;
	}
	catch (const std::exception& e) {
	}
	try {
		B& baseB = dynamic_cast<B&>(p);
		(void)baseB;
		std::cout << "Referenced is B" << std::endl;
	}
	catch (const std::exception& e) {
	}
	try {
		C& baseC = dynamic_cast<C&>(p);
		(void)baseC;
		std::cout << "Referenced is C" << std::endl;
	}
	catch (const std::exception& e) {
	}
}

int main ( void ) {
	Base* secret;

	secret = generate();
	identify(secret);
	identify(*secret);
	delete secret;
}
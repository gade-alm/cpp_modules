#include "Serializer.hpp"

int main ( void ) {
	{
	Data		original = {.name = "Gabriel", .age = 29};
	Data*		ptr;
	uintptr_t	value;

	std::cout << "Value of original name: " <<original.name << std::endl << "Value of original age: " << original.age << std::endl;
	std::cout << "------SERIALIZING------" << std::endl;
	value = Serializer::serialize(&original);
	std::cout << "------DESERIALIZING------" << std::endl;
	ptr = Serializer::deserialize(value);
	std::cout << "Value of ptr name: " << ptr->name << std::endl << "Value of ptr age: " <<ptr->age << std::endl;
	}
}

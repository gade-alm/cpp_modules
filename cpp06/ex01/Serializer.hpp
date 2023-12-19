#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>

struct Data {
	std::string	name;
	int			age;
};

class Serializer{
	private:
		Serializer( void );
		Serializer( const Serializer& copy );
		Serializer& operator=( const Serializer& copy );
		~Serializer( void );
	public:
		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );
};

#endif
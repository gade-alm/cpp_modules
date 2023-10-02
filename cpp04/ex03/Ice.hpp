#ifndef ICE_HPP
# define ICE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria {
	protected:

	public:
		Ice();
		~Ice();
		Ice ( const Ice& obj);
		Ice& operator=( const Ice& obj );

		AMateria* clone() const;
		void	use(ICharacter& target);
};

#endif
#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	protected:

	public:
		Ice();
		~Ice();
		Ice ( const Ice& obj);
		Ice& operator=( const Ice& obj );

		AMateria* clone() const;
		void	use(int idx, ICharacter& target);
};

#endif
#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria {

	public:
		Ice();
		Ice(const AMateria &src);
		Ice &operator=(const AMateria &src);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

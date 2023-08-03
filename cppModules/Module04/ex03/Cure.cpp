#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure") {
}

Cure::Cure(const AMateria &src) {
	*this = src;
}

Cure	&Cure::operator=(const AMateria &src) {
	if (this == &src)
		return (*this);
	this->type = src.getType();
	return (*this);
}

Cure::~Cure() {
}

AMateria* Cure::clone() const {
	AMateria *c = new Cure();
	return (c);
}

void Cure::use(ICharacter& target) {
	std::cout << "Cure: * heals " << target.getName() << "’s wounds *"<< std::endl;
}
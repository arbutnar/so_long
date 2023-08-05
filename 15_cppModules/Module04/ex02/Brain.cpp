#include "Brain.hpp"

Brain::Brain() {
	std::cout << "default Brain constructed" << std::endl;
}

Brain::Brain(const Brain &src) {
	*this = src;
}

Brain &Brain::operator=(const Brain &src) {
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain decostructor called" << std::endl;
}

#include "Brain.hpp"

Brain::Brain()
	: ideas (0) {
	std::cout << "Brain defaul constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src) {
	std::cout << "Brain copy assignment operator" << std::endl;
	if (this != &src)
		this->ideas = src.ideas;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain decostructor called" << std::endl;
}

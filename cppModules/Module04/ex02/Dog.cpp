#include "Dog.hpp"

Dog::Dog()
	: Animal() {
	this->type = "Dog";
	std::cout << "default Dog constructed" << std::endl;
}

Dog::Dog(const Dog &src) {
	*this = src;
	std::cout << "Dog copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
	std::cout << "Dog copy assignment constructor" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog decostructor called" << std::endl;
}

void	Dog::makeSound() {
	std::cout << "Woof woof" << std::endl;
}

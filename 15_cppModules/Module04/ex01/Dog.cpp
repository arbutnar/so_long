#include "Dog.hpp"

Dog::Dog()
	: Animal() {
	this->type = "dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src) {
	std::cout << "Dog copy assignment operator" << std::endl;
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

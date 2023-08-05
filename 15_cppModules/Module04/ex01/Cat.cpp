#include "Cat.hpp"

Cat::Cat()
	: Animal() {
	this->type = "Cat";
	std::cout << "default Cat constructed" << std::endl;
}

Cat::Cat(const Cat &src) {
	*this = src;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	std::cout << "Cat copy assignment constructor" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat decostructor called" << std::endl;
}

void	Cat::makeSound() {
	std::cout << "Meow meow" << std::endl;
}

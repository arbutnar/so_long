#include "Cat.hpp"

Cat::Cat()
	: Animal() {
	this->type = "cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) {
	std::cout << "Cat copy constructor" << std::endl;
	*this = src;
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

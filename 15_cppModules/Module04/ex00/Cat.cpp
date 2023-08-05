#include "Cat.hpp"

Cat::Cat()
    : Animal() {
		this->type = "cat";
	    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat() {
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	std::cout << "Cat copy assignment operator" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meow meow" << std::endl;
}

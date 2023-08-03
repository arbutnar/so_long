#include "Cat.hpp"

Cat::Cat()
    : Animal() {
		this->type = "Cat";
	    std::cout << "default Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat deconstructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow meow" << std::endl;
}

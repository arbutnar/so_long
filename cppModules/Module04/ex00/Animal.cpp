#include "Animal.hpp"

Animal::Animal()
	: type (" ") {
		std::cout << "default Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal deconstructor called" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type); 
}
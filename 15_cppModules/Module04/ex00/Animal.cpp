#include "Animal.hpp"

Animal::Animal()
	: type ("generic animal") {
		std::cout << "default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src) {
	std::cout << "Animal copy assignment operator" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type); 
}
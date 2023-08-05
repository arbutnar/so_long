#include "Animal.hpp"

Animal::Animal()
	: type ("generic animal") {
		this->brain = new Brain();
		std::cout << "default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal() {
	delete (this->brain);
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src) {
	std::cout << "Animal copy assignment operator" << std::endl;
	if (this != &src) {
		this->type = src.type;
		if (this->brain != NULL)
			delete (this->brain);
		this->brain = new Brain(*(src.brain));
	}
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type); 
}
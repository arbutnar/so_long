#include "Animal.hpp"

Animal::Animal()
	: type (" ") {
		this->brain = new Brain();
		std::cout << "default Animal constructed" << std::endl;
}

Animal::Animal(const Animal &src) {
	*this = src;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &src) {
	std::cout << "Animal copy assignment constructor" << std::endl;
	if (this == &src)
		return (*this);
	if (this->brain != NULL)
		delete (this->brain);
	this->brain = new Brain(*(src.brain));
	return (*this);
}

Animal::~Animal() {
	delete (this->brain);
	std::cout << "Animal decostructor called" << std::endl;
}

void	Animal::makeSound() {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() {
	return (this->type);
}
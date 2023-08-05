#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type ("generic wrong animal") {
		std::cout << "default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << "Wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type); 
}
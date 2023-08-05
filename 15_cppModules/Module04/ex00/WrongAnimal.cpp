#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type (" ") {
		std::cout << "default WrongAnimal constructor called" << tsd::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal deconstructor called" << tsd::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type); 
}
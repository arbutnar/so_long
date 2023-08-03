#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal() {
		this->type = "WrongCat";
		std::cout << "default WrongCat contructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat decontructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong meow meow sound" << std::endl;
}

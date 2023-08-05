#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal() {
		this->type = "wrong cat";
		std::cout << "default WrongCat contructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) {
	std::cout << "WrongCat copy contructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat decontructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
	std::cout << "WrongCat copy assignment operator" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "Wrong meow meow sound" << std::endl;
}

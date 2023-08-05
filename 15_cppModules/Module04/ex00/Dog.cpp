#include "Dog.hpp"

Dog::Dog()
    : Animal() {
		this->type = "Dog";
        std::cout << "default Dog constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog deconstructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woff woof" << std::endl;
}

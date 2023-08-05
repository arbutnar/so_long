#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {

    const Animal* meta = new Animal();
    const WrongAnimal* meta2 = new WrongAnimal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* i2 = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << i2->getType() << " " << std::endl;
    std::cout << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;
    i2->makeSound();
    meta2->makeSound();

    delete meta;
    delete j;
    delete i;
    delete meta2;
    delete i2;

    return 0;
}
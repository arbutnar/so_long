#include "Cat.hpp"
#include "Dog.hpp"

int main() {

	//const Animal* j = new Animal();	Compiler Error due to trying to instantiate abstract obj
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	return 0;
}
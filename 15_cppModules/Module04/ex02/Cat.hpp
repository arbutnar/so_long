#pragma once
#include "Animal.hpp"

class Cat: public Animal {

	public:
		Cat();
		Cat(const Cat &src);
		~Cat( void );

		Cat &operator=(const Cat &src);
		
		void makeSound();
};
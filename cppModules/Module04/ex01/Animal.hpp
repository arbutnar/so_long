#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
	protected:
		std::string type;
		Brain *brain;
	public:
		Animal();
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		virtual ~Animal( void );
		virtual void makeSound();
		std::string getType();
};
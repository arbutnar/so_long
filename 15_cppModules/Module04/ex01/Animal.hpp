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
	    virtual ~Animal();

		Animal &operator=(const Animal &src);

	    virtual void makeSound() const;
		std::string getType() const;
};
#pragma once 

#include "Animal.hpp"

class WrongAnimal {
	protected:
	    std::string type;
	public:
	    WrongAnimal();
	    virtual ~WrongAnimal();
	    void makeSound() const;
		std::string getType() const;
};

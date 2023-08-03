#include "FragTrap.hpp"

FragTrap::FragTrap( void )
	: ClapTrap() {
		std::cout << "\033[1;34mFragTrap default constructor for " << this->name << "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name) {
		this->hp = 100;
		this->ep = 100;
		this->dp = 30;
		std::cout << "\033[1;34mFragTrap one-arg constructor for " << this->name << "\033[0m" << std::endl;
}

FragTrap::~FragTrap( void ) {
		std::cout << "\033[1;34mFragTrap deconstructor for " << this->name << "\033[0m" << std::endl;
}

void FragTrap::highFiveGuys(void) {
	std::cout << "High five request|" << std::endl;
}
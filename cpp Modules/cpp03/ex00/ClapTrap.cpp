#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string n) 
	: name {n} {
	std::cout << "Constructor called for ClapTrap" << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Deconstructor called for ClapTrap" << name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energypoints <= 0)
		std::cout << "ClapTrap can't attack" << std::endl;
	else {
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", causing " << attackdamage << " points of damage!" << std::endl;
		energypoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitpoints <= 0)
		std::cout << "ClapTrap was killed" << std::endl;
	else {
		std::cout << "ClapTrap " << name << " took " << amount << " damage points";
		std::cout << std::endl;
		hitpoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energypoints <= 0)
		std::cout << "ClapTrap can't repair itself" << std::endl;
	else {
		std::cout << "ClapTrap " << name << " repair itself with " << amount << " hit points";
		std::cout << std::endl;
		energypoints -= 1;
	}
}
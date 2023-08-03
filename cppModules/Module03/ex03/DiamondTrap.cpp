#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ScavTrap(), FragTrap(){
		std::cout << "\033[1;34mDiamondTrap default constructor\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + " clap_name"), ScavTrap(name), FragTrap(name), name (name) {
		FragTrap::hp = 100;
    	ScavTrap::ep = 50;
    	FragTrap::dp = 30;
		std::cout << "\033[1;34mDiamondTrap " << this->name << " constructed\033[0m" << std::endl;
} 

DiamondTrap::~DiamondTrap() {
		std::cout << "\033[1;34mDiamondTrap " << this->name << " decostructed\033[0m" << std::endl;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "Am I " << this->name << '?' << std::endl;
	std::cout << "Or am I " << ClapTrap::name << "?\nThought I was me." << std::endl;
}
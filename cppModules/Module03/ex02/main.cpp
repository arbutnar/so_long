#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	FragTrap fraggy("Fraggy");

	fraggy.attack("Bimbo");
	fraggy.highFiveGuys();

	ScavTrap scavvy("Scavvy");
	scavvy.attack("fraggy");
	fraggy.beRepaired(5);
}
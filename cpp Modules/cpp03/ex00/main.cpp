#include "ClapTrap.hpp"

int main() {
	ClapTrap mattwe("mattwe");
	ClapTrap arwi("arwi");

	arwi.attack("mattwe");
	mattwe.takeDamage(0);
	mattwe.beRepaired(11);
}
#pragma once

#include <iostream>

class ClapTrap {
	private:
		std::string	name;
		int			hitpoints {10};
		int			energypoints {10};
		int			attackdamage {0};
	public:
		ClapTrap( std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
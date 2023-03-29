#pragma once

#include <iostream>

class	Zombie
{
	private:
		std::string name;
	public:
		Zombie( );
		~Zombie( );
		void set_name( std::string n);
		void announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
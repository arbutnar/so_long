#pragma once

#include <iostream>
#include <string>

class	Zombie{
	private:
		std::string name;
	public:
		Zombie( );
		~Zombie( );
		void	set_name( std::string n );
		void	announce( void );
};

Zombie*		zombieHorde( int N, std::string name );
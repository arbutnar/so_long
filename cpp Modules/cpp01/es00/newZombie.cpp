#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie	*newZombie;

	newZombie = new Zombie;
	newZombie->set_name( name );
	return (newZombie);
}
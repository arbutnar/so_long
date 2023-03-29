#include "Zombie.hpp"

int main ()
{
	Zombie	*Foo;

	Foo = newZombie("Foo");
	Foo->announce();
	randomChump("Boo");
	delete Foo;
	return (0);
}
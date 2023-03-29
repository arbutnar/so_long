#include "Zombie.hpp"

int main() {
	int i;
	Zombie *horde;

	std::string name = "Foo";
	int N = 5;

	horde = zombieHorde(N, name);
	for (i = 0; i < N; i++)
		(horde + 1)->announce();
	delete [] horde;
	return (0);
}
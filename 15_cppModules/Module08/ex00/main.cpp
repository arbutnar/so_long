#include "easyfind.hpp"

template <typename T>
void	easyfind(T container, int i) {
	for (int idx = 0; container[idx]; idx++) {
		if (container[idx] == i) {
			std::cout << i << " found at position " << idx + 1 << std::endl;
			return ;
		}
	}
	throw EasyFind::CannotFind();
}

int main() {

	try {
		std::array<int, 10> container = { 4, 5, 100, 200, 90, 1 };
		easyfind(container, 5);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
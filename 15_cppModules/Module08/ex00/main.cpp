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
		int arr[] = { 4, 5, 100, 200, 90, 1 };
		std::vector<int> container(arr, arr + 7);
		easyfind(container, 5);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

	ScalarConverter conv;

	if (argc != 2)
		std::cout << "Arg error" << std::endl;
	else
		conv.convert(argv[1]);

	return 0;
}
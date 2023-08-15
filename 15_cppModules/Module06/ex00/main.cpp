#include "ScalarConverter.hpp"

bool isNumber(std::string in) {
	try {
		int i =		std::stoi(in.c_str());
		std::cout << i;
		return true;
	} catch (const std::invalid_argument) {
		return false;
	}
}

int main(int argc, char **argv) {

	if (argc != 2){
		std::cout << "Arg error" << std::endl;
		return 1;}
	std::string in = argv[1];

	if (!isNumber(in) && in.length() != 1)
		std::cout << "Error: input is not a char nor number" << std::endl;


	return 0;
}
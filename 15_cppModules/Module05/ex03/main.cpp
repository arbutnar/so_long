#include "Intern.hpp"

int main() {


	try {
		Intern intern;
		intern.makeForm("PresidentialPardonForm", "balbio");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
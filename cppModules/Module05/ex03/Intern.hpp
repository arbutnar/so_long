#pragma once
#include "AForm.hpp"

class Intern {

	public:
		Intern();
		~Intern();

		AForm* makeForm(std::string name, std::string target);
};

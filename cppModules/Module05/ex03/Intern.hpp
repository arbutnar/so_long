#pragma once
#include <cstring>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

	private:
		static const std::string forms[3];

	public:
		class CannotMakeForm;

		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

		AForm *makeForm(std::string name, std::string target);
};

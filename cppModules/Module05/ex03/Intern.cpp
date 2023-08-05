#include "Intern.hpp"

class Intern::CannotMakeForm : public std::exception {
	public:
		virtual const char* what() const throw() { return("\033[1;31mCannot make form with given name\033[0m"); }
};

const std::string Intern::forms[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

Intern::Intern() {
	//std::cout << "Default Intern contructed" << std::endl;
}

Intern::Intern(const Intern &src) {
	//std::cout << "Copy of Interrn contructed" << std::endl;
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	//std::cout << "Copy assignment operator" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

Intern::~Intern() {
	//std::cout << "Intern deconstructed" << std::endl;	
}

AForm *Intern::makeForm(std::string name, std::string target) {
	int idx = 0;

	while(idx < 3) {
		try {
			if (!strcmp(this->forms[idx].c_str(), name.c_str())) {
				std::cout << "Intern creates " << this->forms[idx] << std::endl;
				break ;
			}
		} catch (s)
		
		idx++;
	}

	switch (idx) {
		case 0 :
			return (new ShrubberyCreationForm(target));
		case 1 :
			return (new RobotomyRequestForm(target));
		case 2 :
			return (new PresidentialPardonForm(target));
	}
	return (NULL);
}
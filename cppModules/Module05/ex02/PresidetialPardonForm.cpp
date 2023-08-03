#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm ("PresidentialPradonForm", 25, 5), target (target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

std::string PresidentialPardonForm::getTarget() {
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	AForm::execute(executor);
	try {
		Zaphod();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void PresidentialPardonForm::Zaphod() const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
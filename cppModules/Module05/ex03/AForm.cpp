#include "AForm.hpp"

class AForm::GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("\033[1;31mGrade too low\033[0m"); } 
};

class AForm::GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("\033[1;31mGrade too high\033[0m"); }
};

class AForm::notSigned : public std::exception {
	public:
		virtual const char* what() const throw() { return ("\033[1;31mForm not signed\033[0m"); }
};

AForm::AForm()
	: name ("Unnamed"), isSigned (false), gradeToSign(0), gradeToExec(0) {
}

AForm::AForm (std::string n, int gts, int gte)
	: name (n), isSigned (false), gradeToSign(gts), gradeToExec(gte) {
	if (this->gradeToSign < 1 || this->gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (this->gradeToSign > 150 || this->gradeToExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {
}

std::string AForm::getName() const {
	return (this->name);
}

bool AForm::getIsSigned() const {
	return (this->isSigned);
}

void AForm::setIsSigned(bool state) {
	this->isSigned = state;
}


int AForm::getGradeToSign() const {
	return (this->gradeToSign);
}

int AForm::getGradeToExec() const {
	return (this->gradeToExec);
}

void AForm::beSigned(Bureaucrat *b) {
	std::cout << "AFORM PROSPECTIVE: Requested grade to sign AForm: " << this->getGradeToSign() << std::endl;
	if (b->getGrade() <= this->getGradeToSign()) {
		this->isSigned = true;
		std::cout << "Candidate for signing: " << *b; 
		std::cout << "AForm signed state: " << std::boolalpha << this->getIsSigned() << std::endl;
	}
	else {
		std::cout << "Candidate for signing: " << *b; 
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned)
		throw AForm::notSigned();
	else if (executor.getGrade() > this->getGradeToExec()) {
		std::cout << executor.getName() << " couldn’t execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, AForm &f) {
	os << "AForm name: " << f.getName() << ".\nsigned state: " << f.getIsSigned() << ".\ngrade required to sign: " << f.getGradeToSign() << ".\ngrade required to execute: " << f.getGradeToExec() << ".\n";
	return (os);
}

#include "Form.hpp"

class Form::GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Grade too low"); } 
};

class Form::GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Grade too high"); }
};

Form::Form()
	: name ("Unnamed"), isSigned (false), gradeToSign(0), gradeToExec(0) {
}

Form::Form (std::string n, int gts, int gte)
	: name (n), isSigned (false), gradeToSign(gts), gradeToExec(gte) {
	if (this->gradeToSign < 1 || this->gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (this->gradeToSign > 150 || this->gradeToExec > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {
}

std::string Form::getName() {
	return (this->name);
}

bool Form::getIsSigned() {
	return (this->isSigned);
}

void Form::setIsSigned(bool state) {
	this->isSigned = state;
}


int Form::getGradeToSign() {
	return (this->gradeToSign);
}

int Form::getGradeToExec() {
	return (this->gradeToExec);
}

void Form::beSigned(Bureaucrat *b) {
	std::cout << "FORM PROSPECTIVE: Requested grade to sign Form: " << this->getGradeToSign() << std::endl;
	if (b->getGrade() <= this->getGradeToSign()) {
		this->isSigned = true;
		std::cout << "Candidate for signing: " << *b; 
		std::cout << "Form signed state: " << std::boolalpha << this->getIsSigned() << std::endl;
	}
	else {
		std::cout << "Candidate for signing: " << *b; 
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &os, Form &f) {
	os << "Form name: " << f.getName() << ".\nsigned state: " << f.getIsSigned() << ".\ngrade required to sign: " << f.getGradeToSign() << ".\ngrade required to execute: " << f.getGradeToExec() << ".\n";
	return (os);
}

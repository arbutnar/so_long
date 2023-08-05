#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() { return ("Grade too low"); }
};

class Bureaucrat::GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() { return ("Grade too high"); }
};

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name (name), grade (grade) {
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    std::cout << "A copy of " << src.name << " was constructed ";
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    std::cout << "through copy assignment" << std::endl;
    if (this == &src)
        return (*this);
    this->grade = src.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat decostructor called" << std::endl;
}

std::string Bureaucrat::getName() {
    return (this->name);
}

int Bureaucrat::getGrade() {
    return (this->grade);
}

void Bureaucrat::incrementGrade(int amount) {
    for (int i = 0; i < amount; i++) {
        if (this->grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        this->grade -= 1;
    }
    std::cout << "Bureaucrat upgraded at " << this->grade << std::endl;
}

void Bureaucrat::decrementGrade(int amount) {
    for (int i = 0; i < amount; i++) {
        if (this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        this->grade += 1;
    }
    std::cout << "Bureaucrat downgraded at " << this->grade << std::endl;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return (os);
}

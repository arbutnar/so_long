#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
	
	public:
		class GradeTooLowException;
		class GradeTooHighException;
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		~Form();

		std::string getName();
		bool getIsSigned();
		void setIsSigned(bool state);
		int getGradeToSign();
		int getGradeToExec();
		void beSigned(Bureaucrat *b);

};

std::ostream &operator<<(std::ostream &os, Form &f);
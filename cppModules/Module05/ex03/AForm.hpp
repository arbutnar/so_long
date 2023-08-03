#pragma once
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
	
	public:
		class GradeTooLowException;
		class GradeTooHighException;
		class notSigned;
		
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		void setIsSigned(bool state);
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(Bureaucrat *b);

		virtual void execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator<<(std::ostream &os, AForm &f);
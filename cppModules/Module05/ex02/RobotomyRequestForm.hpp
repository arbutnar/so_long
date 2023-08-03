#pragma once
#include <unistd.h>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {

	private:
		std::string target;

	public:
		class RobotomyFailure;

		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		std::string getTarget();
		void robotomize() const;
		void execute(Bureaucrat const &executor) const;
};
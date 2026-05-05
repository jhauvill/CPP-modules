#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &second);
	~RobotomyRequestForm();
	void execute(Bureaucrat const &executor) const;
};

#endif
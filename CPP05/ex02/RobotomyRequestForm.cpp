#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &second)
{
	if (this != &second)
		this->_target = second._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	else
	{
		srand(time(NULL));
		int random = rand() % 2;
		std::cout << "DRRRRRRRRRRRRRRR!!! ";
		if (random)
			std::cout << this->_target << " succesfully robotomized" << std::endl;
		else
			std::cout << this->_target << " the robotomy failed" << std::endl;
	}
}

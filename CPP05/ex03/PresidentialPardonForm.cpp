#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &second)
{
	if (this != &second)
		this->_target = second._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

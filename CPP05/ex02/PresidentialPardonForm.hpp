#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &second);
	~PresidentialPardonForm();
	void execute(const Bureaucrat &executor) const;
};


#endif

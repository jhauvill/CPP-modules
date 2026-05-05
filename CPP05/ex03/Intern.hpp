#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:

public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &second);
	~Intern();
	AForm *makeForm(std::string form, std::string target);
};


#endif

#include "Intern.hpp"

static AForm *createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm *createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern &Intern::operator=(const Intern &second)
{
	(void)second;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*forms[])(std::string) = {createShrubbery, createRobotomy, createPresidential};
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return forms[i](target);
		}
	}
	std::cout << "No form matches" << std::endl;
	return NULL;
}

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("bureaucrat1", 2);
		PresidentialPardonForm presidential("public");
		a.signForm(presidential);
		a.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("bureaucrat2", 1);
		RobotomyRequestForm robotomy("chef");
		b.signForm(robotomy);
		b.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("bureaucrat3", 80);
		RobotomyRequestForm robotomy("chef");
		c.signForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat d("bureaucrat4", 139);
		ShrubberyCreationForm shrubbery("chef");
		d.signForm(shrubbery);
		d.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat e("bureaucrat5", 130);
		ShrubberyCreationForm shrubbery("chef");
		e.signForm(shrubbery);
		e.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

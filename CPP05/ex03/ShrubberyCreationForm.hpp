#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &second);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const &executor) const;
};

#endif

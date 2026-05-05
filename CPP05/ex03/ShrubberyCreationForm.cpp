#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &second)
{
	if (this != &second)
		this->_target = second._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	else
	{
		std::ofstream outfile((this->_target + "_shrubbery").c_str());
		outfile << 
"       _-_\n"
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\\\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
"      // \\\\\n" << std::endl;
		outfile.close();
	}
}

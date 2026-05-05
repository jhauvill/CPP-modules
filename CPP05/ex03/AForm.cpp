#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false),  _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_execute < 1 || grade_to_sign < 1)
		throw GradeTooHighException();
	else if (grade_to_execute > 150 || grade_to_sign > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src) :  _name(src._name),  _signed(src._signed),  _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
}

AForm &AForm::operator=(const AForm &second)
{
	if (this != &second)
	{
		this->_signed = second._signed;
	}
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getGradeToSign() const
{
	return this->_grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return this->_grade_to_execute;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_grade_to_sign)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << src.getName() << " signed: " << src.getSigned() << ", grade required to sign it: " << src.getGradeToSign() << ", grade required to execute it: " << src.getGradeToExecute();
	return out;
}

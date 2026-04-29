#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _grade_to_sign;
	const int _grade_to_execute;
public:
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form &src);
	Form &operator=(const Form &second);
	~Form();
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("The grade is too high");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("The grade is too low");
			}
	};

};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif

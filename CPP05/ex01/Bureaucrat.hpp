#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &second);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form);

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);

#endif
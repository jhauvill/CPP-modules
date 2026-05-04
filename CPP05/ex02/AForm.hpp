#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _grade_to_sign;
	const int _grade_to_execute;
public:
	AForm(std::string name, int grade_to_sign, int grade_to_execute);
	AForm(const AForm &src);
	AForm &operator=(const AForm &second);
	virtual ~AForm();
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class NotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("The form is not signed");
			}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &src);


#endif

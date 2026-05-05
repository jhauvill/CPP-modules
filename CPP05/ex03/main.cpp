#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main()
{
	Bureaucrat boss("boss", 20);
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	boss.signForm(*rrf);
	boss.executeForm(*rrf);

	std::cout << "\n";

	Intern secondIntern;
	AForm *aform;
	aform = secondIntern.makeForm("shrubbery creation", "Boss");
	
	std::cout << "\n";

	Intern thirdIntern;
	AForm *newForm;
	newForm = thirdIntern.makeForm("presidential pardon", "President");
	
	std::cout << "\n";

	Intern wrongIntern;
	AForm *wrongForm;
	wrongForm = wrongIntern.makeForm("wrong creation", "wrong");

	delete rrf;
	delete aform;
	delete newForm;
	return 0;
}

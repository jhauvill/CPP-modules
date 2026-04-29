#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a("bureaucrat1", 20);
		Form leave("leave request", 20, 65);
		a.signForm(leave);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("bureaucrat2", 2);
		Form leave("leave request", 1, 65);
		b.signForm(leave);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form test("test", 0, 28);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Form test2("test2", 10, 28);
		std::cout << test2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

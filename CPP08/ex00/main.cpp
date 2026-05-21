#include "easyfind.hpp"

int main(void)
{
	std::vector<int> array(3,5);
	try
	{
		std::cout << *easyfind(array, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::vector<int> array2(3,5);
	try
	{
		std::cout << *easyfind(array, 2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	std::list<int> mylist;

	mylist.push_back(20);
	mylist.push_back(10);
	mylist.push_back(0);
	try
	{
		std::cout << *easyfind(mylist, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << *easyfind(mylist, 18) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: no argument provided." << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmerge;
		pmerge.parseInput(argc, argv);
		pmerge.printBefore();
		pmerge.sort();
		pmerge.printAfter();
		pmerge.printTimes();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

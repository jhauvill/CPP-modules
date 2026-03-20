#include "include.hpp"

void replace(std::ifstream &infile, std::ofstream &outfile, std::string s1, std::string s2)
{
	for (std::string line; std::getline(infile, line); )
	{
		while (line.find(s1) != std::string::npos)
		{
			int index = line.find(s1);
			line.erase(index, s1.size());
			line.insert(index, s2);
			index += s1.size();
		}
		outfile << line << std::endl;
	}
	
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	std::ifstream infile(av[1]);
	if (!infile)
	{
		std::cerr << "Unable to open infile" << std::endl;
		return 1;
	}
	std::string newfile = av[1];
	newfile += ".replace";
	std::string s1 = av[2];
	if (s1.empty())
	{
		std::cerr << "s1 is empty" << std::endl;
		return 1;
	}
	std::string s2 = av[3];
	std::ofstream outfile(newfile.c_str());
	if (!outfile)
	{
		std::cerr << "Unable to open infile" << std::endl;
		return 1;
	}
	replace(infile, outfile, s1, s2);
	infile.close();
	outfile.close();
	return 0;
}

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &second);
	~Brain();
	std::string getIdea(int index) const;
	void setIdea(int index, std::string new_idea);
};

#endif
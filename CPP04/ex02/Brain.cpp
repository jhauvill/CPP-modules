#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

Brain &Brain::operator=(const Brain &second)
{
	std::cout << "Brain copy assignement constructor called" << std::endl;
	if (this != &second)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = second._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index <= 99)
		return this->_ideas[index];
	return "";
}

void Brain::setIdea(int index, std::string new_idea)
{
	if (index >= 0 && index <= 99)
		this->_ideas[index] = new_idea;
}
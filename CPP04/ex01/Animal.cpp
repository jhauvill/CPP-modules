#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = src._type;
}

Animal &Animal::operator=(const Animal &second)
{
	std::cout << "Animal copy assignement operator called" << std::endl;
	if (this != &second)
	{
		this->_type = second._type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "..." << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}
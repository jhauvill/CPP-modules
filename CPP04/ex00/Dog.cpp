#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = src._type;
}

Dog &Dog::operator=(const Dog &second)
{
	std::cout << "Dog copy assignement constructor called" << std::endl;
	if (this != &second)
	{
		this->_type = second._type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}
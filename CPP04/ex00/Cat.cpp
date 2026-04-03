#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = src._type;
}

Cat &Cat::operator=(const Cat &second)
{
	std::cout << "Cat copy assignement constructor called" << std::endl;
	if (this != &second)
	{
		this->_type = second._type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
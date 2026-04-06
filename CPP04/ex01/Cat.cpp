#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain;
	this->_type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
}

Cat &Cat::operator=(const Cat &second)
{
	std::cout << "Cat copy assignement constructor called" << std::endl;
	if (this != &second)
	{
		delete this->_brain;
		this->_brain = new Brain(*second._brain);
		this->_type = second._type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->_brain;
}
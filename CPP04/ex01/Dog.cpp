#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain;
	this->_type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
}

Dog &Dog::operator=(const Dog &second)
{
	std::cout << "Dog copy assignement constructor called" << std::endl;
	if (this != &second)
	{
		delete this->_brain;
		this->_brain = new Brain(*second._brain);
		this->_type = second._type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->_brain;
}
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->_type = "Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->_type = src._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &second)
{
	std::cout << "WrongAnimal copy assignement operator called" << std::endl;
	if (this != &second)
	{
		this->_type = second._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}
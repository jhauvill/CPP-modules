#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
	this->_type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->_type = src._type;
}

AAnimal &AAnimal::operator=(const AAnimal &second)
{
	std::cout << "AAnimal copy assignement operator called" << std::endl;
	if (this != &second)
	{
		this->_type = second._type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "..." << std::endl;
}

std::string AAnimal::getType() const
{
	return this->_type;
}
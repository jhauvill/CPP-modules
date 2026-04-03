#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "Cat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->_type = src._type;
}

WrongCat &WrongCat::operator=(const WrongCat &second)
{
	std::cout << "WrongCat copy assignement constructor called" << std::endl;
	if (this != &second)
	{
		this->_type = second._type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
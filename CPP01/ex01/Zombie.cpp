#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << this->_name << ": >: BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " destroyed" << std::endl ;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

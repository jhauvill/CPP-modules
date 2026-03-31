#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &second)
{
	ClapTrap::operator=(second);
	std::cout << "FragTrap Copy assignement operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() 
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
}

void FragTrap::highFivesGuys()
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " is requesting a high five !" << std::endl;
		this->_energyPoints--;
	}
}
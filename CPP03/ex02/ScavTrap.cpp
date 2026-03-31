#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &second)
{
	ClapTrap::operator=(second);
	std::cout << "ScavTrap Copy assignement operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate()
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
		this->_energyPoints--;
	}
}

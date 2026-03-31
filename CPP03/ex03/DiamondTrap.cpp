#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	_energyPoints = ScavTrap::_energyPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &second)
{
	if (this != &second)
	{
		ClapTrap::operator=(second);
		_name = second._name;
	}
	std::cout << "DiamondTrap Copy assignement operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << this->_name << ", ClapTrap name : " << ClapTrap::_name << std::endl;
}
#include "Character.hpp"

Character::Character(std::string name)
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_floor_size = 200;
	for (int i = 0; i < this->_floor_size; i++)
		this->_floor[i] = NULL;
}

Character::Character(const Character &src)
{
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = src._inventory[i];
}

Character &Character::operator=(const Character &second)
{
	if (this != &second)
	{
		this->_name = second._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			this->_inventory[i] = second._inventory[i];
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < this->_floor_size; i++)
	{
		if (this->_floor[i])
		{
			delete this->_floor[i];
			this->_floor[i] = NULL;
		}
	}
}

const std::string &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		for (int i = 0; i < this->_floor_size; i++)
		{
			if (!this->_floor[i])
			{
				this->_floor[i] = this->_inventory[idx];
				this->_inventory[idx] = NULL;
				break;
			}
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_inventory[idx])
			_inventory[idx]->use(target);
	}
}

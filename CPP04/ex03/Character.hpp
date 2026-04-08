#ifndef CHARACTER_CPP
#define CHARACTER_CPP

#include "ICharacter.hpp"

class Character : public ICharacter
{

private:
	std::string _name;
	AMateria *_inventory[4];
	int _floor_size;
	AMateria *_floor[];
public:
	Character(std::string name);
	Character(const Character &src);
	Character &operator=(const Character &second);
	virtual ~Character();
	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
};

#endif
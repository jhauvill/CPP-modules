#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	
	ICharacter* bob = new Character("bob");
	
	me->use(3, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(10, *bob);

	AMateria* unknown = src->createMateria("unknown");
	me->equip(unknown);

	me->unequip(0);
	me->use(0, *bob);
	me->unequip(10);
	bob->unequip(0);

	delete bob;
	delete me;
	delete src;

	return 0;
}

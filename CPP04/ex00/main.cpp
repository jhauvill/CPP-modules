#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "======Good class======" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "\n ======Wrong class======" << std::endl;
	const WrongAnimal* t = new WrongAnimal();
	const WrongAnimal* e = new WrongCat();
	std::cout << t->getType() << " " << std::endl;
	std::cout << e->getType() << " " << std::endl;
	t->makeSound();
	e->makeSound();
	delete t;
	delete e;

	return 0;
}
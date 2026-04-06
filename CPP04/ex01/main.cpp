#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n=====Dog=====" << std::endl;
	Dog a;
	a.getBrain()->setIdea(0, "eat");

	Dog b(a);
	b.getBrain()->setIdea(0, "sleep");

	std::cout << a.getBrain()->getIdea(0) << std::endl;
	std::cout << b.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n=====Cat=====" << std::endl;
	Cat c;
	a.getBrain()->setIdea(9, "eat");

	Cat d(c);
	b.getBrain()->setIdea(9, "sleep");

	std::cout << c.getBrain()->getIdea(9) << std::endl;
	std::cout << d.getBrain()->getIdea(9) << std::endl;

	std::cout << "=====Destruction=====" << std::endl;
	return 0;
}

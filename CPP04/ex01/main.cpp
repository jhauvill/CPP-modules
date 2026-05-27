#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=====Test 1: Base tests=====" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n=====Test 2: Dog deep copy=====" << std::endl;
	Dog a;
	a.getBrain()->setIdea(0, "eat");
	a.getBrain()->setIdea(50, "run");

	Dog b(a);
	b.getBrain()->setIdea(0, "sleep");
	b.getBrain()->setIdea(50, "jump");

	std::cout << "Dog a idea[0]: " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog b idea[0]: " << b.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog a idea[50]: " << a.getBrain()->getIdea(50) << std::endl;
	std::cout << "Dog b idea[50]: " << b.getBrain()->getIdea(50) << std::endl;

	std::cout << "\n=====Test 3: Cat deep copy=====" << std::endl;
	Cat c;
	c.getBrain()->setIdea(9, "eat");
	c.getBrain()->setIdea(99, "run");

	Cat d(c);
	d.getBrain()->setIdea(9, "sleep");
	d.getBrain()->setIdea(99, "jump");

	std::cout << "Cat c idea[9]: " << c.getBrain()->getIdea(9) << std::endl;
	std::cout << "Cat d idea[9]: " << d.getBrain()->getIdea(9) << std::endl;
	std::cout << "Cat c idea[99]: " << c.getBrain()->getIdea(99) << std::endl;
	std::cout << "Cat d idea[99]: " << d.getBrain()->getIdea(99) << std::endl;

	std::cout << "\n=====Test 4: Assignment operator=====" << std::endl;
	Dog e;
	e.getBrain()->setIdea(0, "original");
	Dog f;
	f = e;
	f.getBrain()->setIdea(0, "modified");
	std::cout << "Dog e idea[0]: " << e.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog f idea[0]: " << f.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n=====Test 5: Array of Animals=====" << std::endl;
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n=====End of main=====" << std::endl;
	return 0;
}

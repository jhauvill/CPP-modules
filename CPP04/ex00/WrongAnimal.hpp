#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &second);
	~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};


#endif
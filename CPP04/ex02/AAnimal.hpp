#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &second);
	virtual ~AAnimal();
	virtual void makeSound() const = 0;
	std::string getType() const;
};


#endif
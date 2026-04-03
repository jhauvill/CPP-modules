#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	
public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &second);
	~Cat();
	void makeSound() const;
};

#endif
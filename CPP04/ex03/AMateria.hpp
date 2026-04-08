#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string _type;
public:
	AMateria(const std::string &type);
	AMateria(const AMateria &src);
	AMateria &operator=(const AMateria &second);
	virtual ~AMateria();
	const std::string &getType() const; 

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
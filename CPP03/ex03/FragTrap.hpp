#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		FragTrap &operator=(const FragTrap &second);
		~FragTrap();
		void attack(const std::string &target);
		void highFivesGuys(void);
};

#endif
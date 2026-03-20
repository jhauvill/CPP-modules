#include "Harl.hpp"

void Harl::complain(std::string level)
{
	Harl harl;
	std::string string_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr_debug)(void) = &Harl::_debug;
	void (Harl::*ptr_info)(void) = &Harl::_info;
	void (Harl::*ptr_warning)(void) = &Harl::_warning;
	void (Harl::*ptr_error)(void) = &Harl::_error;
	void (Harl::*ptr_tab[4])(void) = {ptr_debug, ptr_info, ptr_warning, ptr_error};
	for (int i = 0; i < 4; i++)
	{
		if (level == string_tab[i])
			(this->*ptr_tab[i])();
	}
}
void Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

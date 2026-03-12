#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : count(-1), oldest(0) {}

void PhoneBook::print_search(int index)
{
	std::cout << std::left << std::setw(10) <<  index << "|";
	truncate_print(this->contacts[index].getFirstName());
	std::cout << "|";
	truncate_print(this->contacts[index].getLastName());
	std::cout << "|";
	truncate_print(this->contacts[index].getNickname());
	std::cout << "|" << std::endl;
}

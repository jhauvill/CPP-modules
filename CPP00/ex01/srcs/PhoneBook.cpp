#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : count(-1), oldest(0) {}

void PhoneBook::print_search(int index)
{
	std::cout << std::setw(10) << index << "|";
	truncate_print(this->contacts[index].getFirstName());
	std::cout << "|";
	truncate_print(this->contacts[index].getLastName());
	std::cout << "|";
	truncate_print(this->contacts[index].getNickname());
	std::cout << "|" << std::endl;
}

void PhoneBook::print_full_contact(int index)
{
	std::cout << "First name: "<< this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: "<< this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: "<< this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}

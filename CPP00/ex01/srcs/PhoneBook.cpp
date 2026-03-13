#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _oldest(0) {}

void PhoneBook::set_count(int count)
{
	if (count <= 8)
		this->_count = count;
	else
		this->_count = 8;
}

void PhoneBook::set_oldest(int oldest)
{
	if (oldest < 8)
		this->_oldest = oldest;
	else
		this->_oldest = 7;
}

int PhoneBook::get_count()
{
	return this->_count;
}

int PhoneBook::get_oldest()
{
	return this->_oldest;
}

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

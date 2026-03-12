#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "utils.hpp"
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook() {};
	void print_search(int index);
	Contact contacts[8];
	int count;
	int oldest;
};

#endif
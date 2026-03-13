#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "utils.hpp"
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook() {};
	void set_oldest(int oldest);
	void set_count(int count);
	int get_oldest();
	int get_count();
	void print_search(int index);
	void print_full_contact(int index);
	Contact contacts[8];

private:
	int _count;
	int _oldest;
};

#endif
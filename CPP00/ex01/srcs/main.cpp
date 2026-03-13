#include "../includes/PhoneBook.hpp"

void truncate_print(std::string str)
{
	std::string new_str;
	
	if (str.size() > 10)
	{
		for (int i = 0; i < 9; i++)
			new_str += str[i];
		new_str += '.';
		std::cout << new_str;
	}
	else
		std::cout << std::setw(10) << str;
}

void add(Contact &contact)
{
	std::string input;
	std::cout << "First Name : ";
	std::cin >> input;
	contact.setFirstName(input);
	std::cout << "Last Name : ";
	std::cin >> input;
	contact.setLastName(input);
	std::cout << "Nickname : ";
	std::cin >> input;
	contact.setNickname(input);
	std::cout << "Phone Number : ";
	std::cin >> input;
	contact.setPhoneNumber(input);
	std::cout << "Darkest Secret : ";
	std::cin >> input;
	contact.setDarkestSecret(input);
}

int main()
{
	int index;
	PhoneBook phonebook;
	std::string command;
	int count;
	int oldest;

	// Test
	//phonebook.contacts[0].setFirstName("Alice"); phonebook.contacts[0].setLastName("Smith"); phonebook.contacts[0].setNickname("Ali");
	//phonebook.contacts[0].setPhoneNumber("0600000001"); phonebook.contacts[0].setDarkestSecret("secret1");

	//phonebook.contacts[1].setFirstName("Bob"); phonebook.contacts[1].setLastName("Jones"); phonebook.contacts[1].setNickname("Bobby");
	//phonebook.contacts[1].setPhoneNumber("0600000002"); phonebook.contacts[1].setDarkestSecret("secret2");

	//phonebook.contacts[2].setFirstName("Charlie"); phonebook.contacts[2].setLastName("Brown"); phonebook.contacts[2].setNickname("Chuck");
	//phonebook.contacts[2].setPhoneNumber("0600000003"); phonebook.contacts[2].setDarkestSecret("secret3");

	//phonebook.contacts[3].setFirstName("Diana"); phonebook.contacts[3].setLastName("Prince"); phonebook.contacts[3].setNickname("Di");
	//phonebook.contacts[3].setPhoneNumber("0600000004"); phonebook.contacts[3].setDarkestSecret("secret4");

	//phonebook.contacts[4].setFirstName("Eve"); phonebook.contacts[4].setLastName("Wilson"); phonebook.contacts[4].setNickname("Evie");
	//phonebook.contacts[4].setPhoneNumber("0600000005"); phonebook.contacts[4].setDarkestSecret("secret5");

	//phonebook.contacts[5].setFirstName("Frank"); phonebook.contacts[5].setLastName("Miller"); phonebook.contacts[5].setNickname("Franky");
	//phonebook.contacts[5].setPhoneNumber("0600000006"); phonebook.contacts[5].setDarkestSecret("secret6");

	//phonebook.contacts[6].setFirstName("Grace"); phonebook.contacts[6].setLastName("Lee"); phonebook.contacts[6].setNickname("Gracie");
	//phonebook.contacts[6].setPhoneNumber("0600000007"); phonebook.contacts[6].setDarkestSecret("secret7");

	//phonebook.contacts[7].setFirstName("Henry"); phonebook.contacts[7].setLastName("Ford"); phonebook.contacts[7].setNickname("Hank");
	//phonebook.contacts[7].setPhoneNumber("0600000008"); phonebook.contacts[7].setDarkestSecret("secret8");
	//phonebook.set_count(9);
	//phonebook.set_oldest(0);
	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore();
			break;
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			if (phonebook.get_count() < 8)
			{
				count = phonebook.get_count();
				add(phonebook.contacts[count]);
				phonebook.set_count(count++);
			}
			else
			{
				oldest = phonebook.get_oldest();
				add(phonebook.contacts[oldest]);
				if (phonebook.get_oldest() < 7)
					phonebook.set_oldest(oldest++);
				else
					phonebook.set_oldest(0);
			}
		}
		else if (command == "SEARCH")
		{
			for (int i = 0; i < phonebook.get_count(); i++)
				phonebook.print_search(i);
			std::cout << "Enter an index: ";
			std::cin >> index;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Wrong index" << std::endl;
			}
			else if (index < 8 && index < phonebook.get_count() && index >= 0)	
				phonebook.print_full_contact(index);
			else
				std::cout << "Wrong index" << std::endl;
		}
	}
	return 0;
}

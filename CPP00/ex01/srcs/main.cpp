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
		std::cout << std::left << std::setw(10) << str;
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
	//phonebook.count = 8;
	//phonebook.oldest = 0;
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			if (phonebook.count < 7)
			{
				phonebook.count++;
				add(phonebook.contacts[phonebook.count]);
			}
			else
			{
				add(phonebook.contacts[phonebook.oldest]);
				if (phonebook.oldest < 7)
					phonebook.oldest++;
				else
					phonebook.oldest = 0;
			}
		}
		else if (command == "SEARCH")
		{
			for (int i = 0; i < phonebook.count; i++)
				phonebook.print_search(i);
			std::cout << "Enter an index: ";
			std::cin >> index;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Wrong index" << std::endl;
			}
			else if (index < 8 && index <= phonebook.count && index >= 0)	
				phonebook.print_full_contact(index);
			else
				std::cout << "Wrong index" << std::endl;
		}
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
	return 0;
}

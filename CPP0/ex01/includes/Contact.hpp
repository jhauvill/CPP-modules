#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "utils.hpp"

class Contact
{
public:
	Contact() {};
	~Contact() {};
	void setPhoneNumber(std::string phone_number);
	void setFirstName(std::string first_name);
	void setLastName(std::string last_name);
	void setNickname(std::string nickname);
	void setDarkestSecret(std::string darkest_secret);
	std::string getPhoneNumber();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getDarkestSecret();

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string	phone_number;
	std::string darkest_secret;

};

#endif

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
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string	_phone_number;
	std::string _darkest_secret;

};

#endif

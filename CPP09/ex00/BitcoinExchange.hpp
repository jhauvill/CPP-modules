#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdexcept>


class BitcoinExchange
{
private:
	std::map<std::string, float> _db;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &second);
	~BitcoinExchange();

	void fillDb(const std::string &filename);
	float validDate(std::string &date);
	void validNumber(float num);
	void processInput(const std::string &input);
};


#endif

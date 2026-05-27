#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	this->_db = src._db;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &second)
{
	if (this != &second)
		this->_db = second._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::fillDb(const std::string &filename)
{
	std::ifstream data(filename.c_str());

	if (!data.is_open())
		throw std::runtime_error("Error: Could not open database");

	std::string line;
	int pos;

	std::getline(data, line);
	while (std::getline(data, line))
	{
		pos = line.find(',');
		std::stringstream ss(line.substr(pos + 1));
		float value;
		ss >> value;
		this->_db[line.substr(0, pos)] = value;
	}
}

float BitcoinExchange::validDate(std::string &date)
{
	std::map<std::string, float>::iterator it;

	it = this->_db.lower_bound(date);
	if (it == this->_db.begin())
		throw std::runtime_error("Error: wrong date.");
	if (it->first != date)
		it--;
	return it->second;
}

void BitcoinExchange::validNumber(float num)
{
	if (num < 0 )
		throw std::out_of_range("Error: not a positive number.");
	else if (num > 1000)
		throw std::out_of_range("Error: too large a number.");
}

void BitcoinExchange::processInput(const std::string &input)
{
	std::ifstream infile(input.c_str());
	std::string line;

	std::getline(infile, line);
	while(std::getline(infile, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << "\n";
			continue;
		}

		std::string date = line.substr(0, pos - 1);

		try
		{
			float price = validDate(date);
			std::stringstream ss(line.substr(pos + 1));
			float value;
			ss >> value;
			validNumber(value);
			std::cout << date << " => " << value << " = " << price * value << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

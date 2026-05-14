#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &second)
{
	(void)second;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static bool isChar(std::string str)
{
	if (str[0] == '\'' && str.size() == 3 && str[str.size() - 1] == '\'')
		return true;
	return false;
}

static bool isFloat(std::string str)
{
	if (str.find('f') != std::string::npos && str.find('.') != std::string::npos)
		return true;
	return false;
}

static bool isDouble(std::string str)
{
	if (str.find('.') != std::string::npos)
		return true;
	return false;
}

static void printFloat(std::string str)
{
	std::string c;
	std::stringstream ss(str.substr(0, str.size() - 1));
	double value;
	ss >> value;

	if (value < 0 || value > 127)
		c = "Impossible";
	else if ((value < 32 && value >= 0) || value == 127)
		c = "Non displayable";
	else
		c = std::string("'") + static_cast<char>(value) + "'";
	if (ss.fail() || ss.eof() == false)
		std::cout << "Invalid literal" << std::endl;
	else if (value > INT_MAX || value < INT_MIN)
		std::cout << std::fixed << std::setprecision(1) << "char: " << c  << "\nint: Impossible" << "\nfloat: " << static_cast<float>(value) << "f\ndouble: " << value << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "char: " << c << "\nint: " << static_cast<int>(value) << "\nfloat: " << value << "f\ndouble: " << static_cast<double>(value) << std::endl;
}

static void printDouble(std::string str)
{
	std::string c;
	std::stringstream ss(str);
	double value;
	ss >> value;

	if (value < 0 || value > 127)
		c = "Impossible";
	else if ((value < 32 && value >= 0) || value == 127)
		c = "Non displayable";
	else
		c = std::string("'") + static_cast<char>(value) + "'";
	if (ss.fail() || ss.eof() == false)
		std::cout << "Invalid literal" << std::endl;
	else if (value > INT_MAX || value < INT_MIN)
		std::cout << std::fixed << std::setprecision(1) << "char: " << c  << "\nint: Impossible" << "\nfloat: " << static_cast<float>(value) << "f\ndouble: " << value << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "char: " << c << "\nint: " << static_cast<int>(value) << "\nfloat: " << static_cast<float>(value) << "f\ndouble: " << value << std::endl;
}

static void printInt(std::string str)
{
	std::string c;
	std::stringstream ss(str);
	double value;
	ss >> value;
	
	if (value < 0 || value > 127)
		c = "Impossible";
	else if ((value < 32 && value >= 0) || value == 127)
		c = "Non displayable";
	else
		c = std::string("'") + static_cast<char>(value) + "'";
	if (ss.fail() || ss.eof() == false)
		std::cout << "Invalid literal" << std::endl;
	else if (value > INT_MAX || value < INT_MIN)
		std::cout << std::fixed << std::setprecision(1) << "char: " << c  << "\nint: Impossible" << "\nfloat: " << static_cast<float>(value) << "f\ndouble: " << value << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "char: " << c  << "\nint: " << static_cast<int>(value) << "\nfloat: " << static_cast<float>(value) << "f\ndouble: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	if (str == "nan" || str == "nanf")
		std::cout << "char: Impossible\nint: Impossible\nfloat: " << static_cast<float>(NAN) << "f\ndouble: " << NAN << std::endl;
	else if (str == "+inf" || str == "+inff")
		std::cout << "char: Impossible\nint: Impossible\nfloat: +" << static_cast<float>(INFINITY) << "f\ndouble: +" << INFINITY << std::endl;
	else if (str == "-inf" || str == "-inff")
		std::cout << "char: Impossible\nint: Impossible\nfloat: " << static_cast<float>(-INFINITY) << "f\ndouble: " << -INFINITY << std::endl;
	else if (isChar(str))
		std::cout << std::fixed << std::setprecision(1) << "char: '" << str[1] << "'\nint: " << static_cast<int>(str[1]) << "\nfloat: " << static_cast<float>(str[1]) << "f\ndouble: " << static_cast<double>(str[1]) << std::endl;
	else if (isFloat(str))
		printFloat(str);
	else if (isDouble(str))
		printDouble(str);
	else
		printInt(str);
}

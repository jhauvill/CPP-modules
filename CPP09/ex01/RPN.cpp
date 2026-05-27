#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	this->_stack = src._stack;
}

RPN &RPN::operator=(const RPN &second)
{
	if (this != &second)
		this->_stack = second._stack;
	return *this;
}

RPN::~RPN()
{
}

void RPN::parse(const std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]))
			this->_stack.push(input[i] - '0');
		else if ((input[i] == '*' || input[i] == '+' || input[i] == '/'
					|| input[i] == '-') && this->_stack.size() > 1)
			operand(input[i]);
		else if (input[i] != ' ')
		{
			std::cerr << "Error\n";
			return ;
		}
	}
	
	if (this->_stack.size() != 1)
		std::cerr << "Error\n";
	else
		std::cout << this->_stack.top() << "\n";
}

void RPN::operand(char c)
{
	int value2 = this->_stack.top();
	this->_stack.pop();

	int value1 = this->_stack.top();
	this->_stack.pop();

	if (c == '*')
		this->_stack.push(value1 * value2);
	else if (c == '+')
		this->_stack.push(value1 + value2);
	else if (c == '-')
		this->_stack.push(value1 - value2);
	else
		this->_stack.push(value1 / value2);
}

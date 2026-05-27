#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cstdlib>

class RPN
{
private:
	std::stack<int> _stack;
	void operand(char c);
public:
	RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &second);
	~RPN();
	void parse(const std::string &input);

};


#endif
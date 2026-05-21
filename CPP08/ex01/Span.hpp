#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _container;
public:
	Span(unsigned int N);
	Span(const Span &src);
	Span &operator=(const Span &second);
	~Span();
	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	template<typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			this->addNumber(*begin);
			begin++;
		}
	}
};

#endif

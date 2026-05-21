#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->_N = N;
}

Span::Span(const Span &src)
{
	this->_N = src._N;
	this->_container = src._container;
}

Span &Span::operator=(const Span &second)
{
	if (this != &second)
	{
		this->_N = second._N;
		this->_container = second._container;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
	if (this->_container.size() == this->_N)
		throw std::out_of_range("Max numbers stored");
	else
		this->_container.push_back(num);
}

int Span::shortestSpan()
{
	if (this->_container.size() <= 1)
		throw std::out_of_range("Not enough elements");

	std::sort(this->_container.begin(), this->_container.end());

	int shortest = this->_container[1] - this->_container[0];

	for (unsigned long i = 0; i < this->_container.size() - 1; i++)
	{
		if (shortest > this->_container[i + 1] - this->_container[i])
			shortest = this->_container[i + 1] - this->_container[i];
	}
	return shortest;
}

int Span::longestSpan()
{
	if (this->_container.size() <= 1)
		throw std::out_of_range("Not enough elements");

	std::sort(this->_container.begin(), this->_container.end());

	int longest = *std::max_element(this->_container.begin(), this->_container.end())
					-*std::min_element(this->_container.begin(), this->_container.end());

	return longest;
}

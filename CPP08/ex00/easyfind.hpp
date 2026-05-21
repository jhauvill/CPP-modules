#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>

template<typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator it = find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("No occurence found");
	return it;
}

#endif
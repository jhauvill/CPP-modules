#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
private:
	T *_array;
	int _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	Array &operator=(const Array &second);
	~Array();

	unsigned int size() const;
	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;
};

#include "Array.tpp"

#endif
#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	_array = new T[0]();
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n]();
	_size = n;
}

template<typename T>
Array<T>::Array(const Array &src)
{
	_array = new T[src._size]();
	for(int i= 0; i < src._size; i++)
	{
		_array[i] = src._array[i];
	}
	_size = src._size;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &second)
{
	if (this != &second)
	{
		delete []_array;
		_array = new T[second._size]();
		for(int i= 0; i < second._size; i++)
		{
		_array[i] = second._array[i];
		}
		_size = second._size;
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete []_array;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
T &Array<T>::operator[](unsigned int i)
	{
	if (i < 0 || i >= size())
		throw std::out_of_range("index out of bounds");
	return (_array[i]);
}

template<typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i < 0 || i >= size())
		throw std::out_of_range("index out of bounds");
	return (_array[i]);
}

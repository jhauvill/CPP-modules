#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F> 
void iter(T *array, int const len, F func)
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

template<typename T, typename F>
void iter(T const *array, int const len, F func)
{
	for(int i = 0; i < len; i++)
		func(array[i]);
}

#endif
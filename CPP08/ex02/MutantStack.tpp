#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
	(void)src;
}
template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &second)
{
	std::stack<T>::operator=(second);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

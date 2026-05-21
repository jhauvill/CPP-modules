#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	
public:
	typedef typename std::deque<T>::iterator iterator;

	MutantStack();
	MutantStack(const MutantStack &src);
	MutantStack &operator=(const MutantStack &second);
	~MutantStack();
	MutantStack<T>::iterator begin();
	MutantStack<T>::iterator end();
};

#include "MutantStack.tpp"

#endif
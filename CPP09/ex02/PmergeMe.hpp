#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <iomanip>
# include <time.h>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &o);
		PmergeMe &operator=(const PmergeMe &o);
		~PmergeMe();

		void parseInput(int argc, char **argv);
		void sort();
		void printBefore() const;
		void printAfter()  const;
		void printTimes()  const;

	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::vector<int>	_original;
		double				_vecTime;
		double				_deqTime;

		void binaryInsertVec(std::vector<int> &a, int l, int r, int v);
		void binaryInsertDeq(std::deque<int>  &a, int l, int r, int v);
		void mergeInsertSortVec(std::vector<int> &arr, int left, int right);
		void mergeInsertSortDeq(std::deque<int>  &arr, int left, int right);
};

#endif

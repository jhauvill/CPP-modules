#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}
PmergeMe::PmergeMe(const PmergeMe &o) : _vec(o._vec), _deq(o._deq), _original(o._original), _vecTime(o._vecTime), _deqTime(o._deqTime) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &o) { if (this != &o) { _vec=o._vec; _deq=o._deq; _original=o._original; _vecTime=o._vecTime; _deqTime=o._deqTime; } return *this; }
PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		int val;
		if (!(iss >> val) || val < 0)
			throw std::invalid_argument("Error: invalid argument: " + std::string(argv[i]));
		std::string leftover;
		if (iss >> leftover)
			throw std::invalid_argument("Error: invalid argument: " + std::string(argv[i]));
		_vec.push_back(val);
		_deq.push_back(val);
		_original.push_back(val);
	}
	if (_vec.empty())
		throw std::invalid_argument("Error: no input provided.");
}

void PmergeMe::printBefore() const
{
	std::cout << "Before:";
	for (size_t i = 0; i < _original.size(); ++i) std::cout << " " << _original[i];
	std::cout << "\n";
}

void PmergeMe::printAfter() const
{
	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); ++i) std::cout << " " << _vec[i];
	std::cout << "\n";
}

void PmergeMe::printTimes() const
{
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << _vecTime << " us\n";
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << _deqTime << " us\n";
}

void PmergeMe::binaryInsertVec(std::vector<int> &a, int l, int r, int v)
{
	while (l < r) { int m = l + (r-l)/2; if (a[m] < v) l=m+1; else r=m; }
	a.insert(a.begin()+l, v);
}

void PmergeMe::binaryInsertDeq(std::deque<int> &a, int l, int r, int v)
{
	while (l < r) { int m = l + (r-l)/2; if (a[m] < v) l=m+1; else r=m; }
	a.insert(a.begin()+l, v);
}

static int jac(int n)
{
	if (n<=0) return 0;
	if (n==1) return 1;
	int a=0,b=1; for(int i=2;i<=n;i++){int c=b+2*a;a=b;b=c;} return b;
}

static std::vector<int> fordJohnsonVec(std::vector<int> arr);

static std::vector<int> fordJohnsonVec(std::vector<int> arr)
{
	int n = (int)arr.size();
	if (n <= 1) return arr;

	for (int i = 0; i+1 < n; i += 2)
		if (arr[i] < arr[i+1]) std::swap(arr[i], arr[i+1]);

	std::vector<std::pair<int,int> > pairs;
	for (int i = 0; i+1 < n; i += 2)
		pairs.push_back(std::make_pair(arr[i], arr[i+1]));
	bool hasExtra = (n % 2 != 0);
	int extra = hasExtra ? arr[n-1] : 0;

	std::vector<int> S;
	for (int i = 0; i < (int)pairs.size(); ++i) S.push_back(pairs[i].first);
	S = fordJohnsonVec(S);

	std::sort(pairs.begin(), pairs.end());

	std::vector<int> sorted(S);
	sorted.insert(sorted.begin(), pairs[0].second);

	if ((int)pairs.size() > 1)
	{
		int pendSize = (int)pairs.size();
		std::vector<bool> done(pendSize, false);
		done[0] = true;

		int k = 1;
		int prev = 1;
		while (prev <= pendSize - 1)
		{
			int curr = jac(k);
			if (curr > pendSize) curr = pendSize;
			if (curr < prev) curr = pendSize;

			for (int i = curr - 1; i >= prev - 1; --i)
			{
				if (i >= pendSize || done[i]) continue;
				int Sval = pairs[i].first;
				int Pval = pairs[i].second;
				std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), Sval);
				int bound = (int)(it - sorted.begin()) + 1;
				int l = 0, r = bound;
				while (l < r) { int m=l+(r-l)/2; if(sorted[m]<Pval) l=m+1; else r=m; }
				sorted.insert(sorted.begin()+l, Pval);
				done[i] = true;
			}
			prev = curr + 1;
			++k;
		}
		for (int i = 0; i < pendSize; ++i)
		{
			if (!done[i])
			{
				int Pval = pairs[i].second;
				int l=0, r=(int)sorted.size();
				while (l<r){int m=l+(r-l)/2; if(sorted[m]<Pval)l=m+1; else r=m;}
				sorted.insert(sorted.begin()+l, Pval);
			}
		}
	}

	if (hasExtra)
	{
		int l=0, r=(int)sorted.size();
		while (l<r){int m=l+(r-l)/2; if(sorted[m]<extra)l=m+1; else r=m;}
		sorted.insert(sorted.begin()+l, extra);
	}

	return sorted;
}

static std::deque<int> fordJohnsonDeq(std::deque<int> arr)
{
	int n = (int)arr.size();
	if (n <= 1) return arr;

	for (int i = 0; i+1 < n; i += 2)
		if (arr[i] < arr[i+1]) std::swap(arr[i], arr[i+1]);

	std::vector<std::pair<int,int> > pairs;
	for (int i = 0; i+1 < n; i += 2)
		pairs.push_back(std::make_pair(arr[i], arr[i+1]));
	bool hasExtra = (n % 2 != 0);
	int extra = hasExtra ? arr[n-1] : 0;

	std::deque<int> S;
	for (int i = 0; i < (int)pairs.size(); ++i) S.push_back(pairs[i].first);
	S = fordJohnsonDeq(S);

	std::sort(pairs.begin(), pairs.end());

	std::deque<int> sorted(S);
	sorted.insert(sorted.begin(), pairs[0].second);

	if ((int)pairs.size() > 1)
	{
		int pendSize = (int)pairs.size();
		std::vector<bool> done(pendSize, false);
		done[0] = true;

		int k = 1;
		int prev = 1;
		while (prev <= pendSize - 1)
		{
			int curr = jac(k);
			if (curr > pendSize) curr = pendSize;
			if (curr < prev) curr = pendSize;

			for (int i = curr - 1; i >= prev - 1; --i)
			{
				if (i >= pendSize || done[i]) continue;
				int Sval = pairs[i].first;
				int Pval = pairs[i].second;
				std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), Sval);
				int bound = (int)(it - sorted.begin()) + 1;
				int l = 0, r = bound;
				while (l < r) { int m=l+(r-l)/2; if(sorted[m]<Pval) l=m+1; else r=m; }
				sorted.insert(sorted.begin()+l, Pval);
				done[i] = true;
			}
			prev = curr + 1;
			++k;
		}
		for (int i = 0; i < pendSize; ++i)
		{
			if (!done[i])
			{
				int Pval = pairs[i].second;
				int l=0, r=(int)sorted.size();
				while (l<r){int m=l+(r-l)/2; if(sorted[m]<Pval)l=m+1; else r=m;}
				sorted.insert(sorted.begin()+l, Pval);
			}
		}
	}

	if (hasExtra)
	{
		int l=0, r=(int)sorted.size();
		while (l<r){int m=l+(r-l)/2; if(sorted[m]<extra)l=m+1; else r=m;}
		sorted.insert(sorted.begin()+l, extra);
	}

	return sorted;
}

void PmergeMe::mergeInsertSortVec(std::vector<int> &arr, int left, int right)
{
	std::vector<int> sub(arr.begin()+left, arr.begin()+right+1);
	sub = fordJohnsonVec(sub);
	for (int i = 0; i <= right-left; ++i)
		arr[left+i] = sub[i];
}

void PmergeMe::mergeInsertSortDeq(std::deque<int> &arr, int left, int right)
{
	std::deque<int> sub(arr.begin()+left, arr.begin()+right+1);
	sub = fordJohnsonDeq(sub);
	for (int i = 0; i <= right-left; ++i)
		arr[left+i] = sub[i];
}

static double getTime()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1e6 + ts.tv_nsec / 1e3;
}

void PmergeMe::sort()
{
	{
		double s = getTime();
		mergeInsertSortVec(_vec, 0, (int)_vec.size()-1);
		_vecTime = getTime() - s;
	}
	{
		double s = getTime();
		mergeInsertSortDeq(_deq, 0, (int)_deq.size()-1);
		_deqTime = getTime() - s;
	}
}

#pragma once

#include <vector>
#include <deque>
#include <set>
#include <string>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void addNumber(int num);
		void sortAndPrint();
	private:
		std::vector<int> vec;
		std::deque<int> deq;

		void mergeInsertSortVector(std::vector<int>& data, int left, int right);
		void mergeInsertSortDeque(std::deque<int>& data, int left, int right);
};


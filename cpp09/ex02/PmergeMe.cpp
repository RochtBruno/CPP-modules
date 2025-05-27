#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::addNumber(int num) {
	vec.push_back(num);
	deq.push_back(num);
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& data, int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	mergeInsertSortVector(data, left, mid);
	mergeInsertSortVector(data, mid + 1, right);

	std::vector<int> temp;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right) {
		if (data[i] < data[j])
			temp.push_back(data[i++]);
		else
			temp.push_back(data[j++]);
	}
	while (i <= mid) temp.push_back(data[i++]);
	while (j <= right) temp.push_back(data[j++]);
	for (i = left; i <= right; ++i)
		data[i] = temp[i - left];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& data, int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	mergeInsertSortDeque(data, left, mid);
	mergeInsertSortDeque(data, mid + 1, right);

	std::deque<int> temp;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right) {
		if (data[i] < data[j])
			temp.push_back(data[i++]);
		else
			temp.push_back(data[j++]);
	}
	while (i <= mid) temp.push_back(data[i++]);
	while (j <= right) temp.push_back(data[j++]);
	for (i = left; i <= right; ++i)
		data[i] = temp[i - left];
}

void PmergeMe::sortAndPrint() {
	int n = vec.size();
	
	std::cout << "Before:";
	for (int i = 0; i < n; ++i) std::cout << " " << vec[i];
	std::cout << std::endl;

	std::clock_t startVec = std::clock();
	mergeInsertSortVector(vec, 0, n - 1);
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
	mergeInsertSortDeque(deq, 0, n - 1);
	std::clock_t endDeq = std::clock();

	std::cout << "After:";
	for (int i = 0; i < n; ++i) std::cout << " " << vec[i];
	std::cout << std::endl;

	double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
	double timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << n << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << n << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}

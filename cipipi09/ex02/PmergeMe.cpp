/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:59:28 by hbettal           #+#    #+#             */
/*   Updated: 2025/05/11 15:58:55 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <ostream>
#include <sys/_types/_ssize_t.h>

//Un = 2^n - Un-1
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe( const PmergeMe &other )
{
	*this = other;
}

PmergeMe::~PmergeMe()
{}

PmergeMe &PmergeMe::operator=( const PmergeMe &other )
{
	if (this != &other)
	{
		this->vec = other.vec;
		this->deq = other.deq;
	}
	return *this;
}
// $> ./PmergeMe 3 5 9 7 4
// Before: 3 5 9 7 4
// After: 3 4 5 7 9
// Time to process a range of 5 elements with std::[..] : 0.00031 us
// Time to process a range of 5 elements with std::[..] : 0.00014 us
void	PmergeMe::saveData( int ac, char **av )
{
	this->vec.resize(ac - 1);
	this->deq.resize(ac - 1);

	for (int i = 1; i < ac; i++)
	{
		if (!std::isdigit(av[i][0]))
			throw "Error";
		this->vec[i - 1] = std::atol(av[i]);
		this->deq[i - 1] = std::atol(av[i]);
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}

unsigned int getNextUn(unsigned int n, unsigned int prev_Un)
{
	return (pow(2, n) - prev_Un);
}

void binarySearch( vecMap &main, vecMap &pend, size_t pairSize, ssize_t right, size_t index)
{
	ssize_t left = 0;
	ssize_t mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (main[mid][pairSize - 1] > pend[index][pairSize - 1])
			right = mid - 1;
		else
			left = mid + 1;
	}
	main.insert(main.begin() + left, pend[index]);
}

void	PmergeMe::recurSort()
{
	sortVec(1);
	sortDeq(1);
	return ;
}

void	PmergeMe::sortVec( size_t pairSize )
{
		vecMap seqq(vec.size() / pairSize);

	if (seqq.size() < 2)
		return ;
	ssize_t k = 0;
	for (size_t i = 0; i < seqq.size(); i++)
	{
		seqq[i].assign(vec.begin() + k, vec.begin() + k + pairSize);
		k += pairSize;
	}
	for (size_t i = 0; i + 1 < seqq.size(); i += 2)
	{
		if (seqq[i][pairSize - 1] > seqq[i + 1][pairSize - 1])
			std::swap(seqq[i], seqq[i + 1]);
	}
	copyContainer(vec, seqq, pairSize);
	sortVec(pairSize * 2);
	for (size_t i = 0, k = 0; i < seqq.size(); i++, k += pairSize)
		std::copy(vec.begin() + k, vec.begin() + k + pairSize, seqq[i].begin());
	vecMap main;
	vecMap pend;
	std::vector<unsigned int> idx;
	std::vector<ssize_t> jacop;
	jacop.push_back(1);
	main.push_back(seqq[0]);
	for (size_t i = 1, k = 2; i < seqq.size(); i += 2)
	{
		main.push_back(seqq[i]);
		if (i + 1 < seqq.size())
		{
			if (jacop.back() - 2 < (ssize_t)pend.size())
				jacop.push_back(getNextUn(k++, jacop.back()));
			pend.push_back(seqq[i + 1]);
		}
	}
	unsigned int prevJacop;
	unsigned int currJacop;
	k = 1;
	while (idx.size() < pend.size() && jacop.size() > 1)
	{
		prevJacop = jacop[k - 1];
		if (k < (ssize_t)jacop.size())
		{
			currJacop = jacop[k];
			while (currJacop > prevJacop)
			{
				if (pend.size() > currJacop - 2)
					idx.push_back(currJacop - 2);
				currJacop--;
			}
		}
		else
		{
			prevJacop = jacop[k - 1]++;
			while (idx.size() < pend.size())
			{
				idx.push_back(prevJacop - 2);
				prevJacop++;
			}
		}
		k++;
	}
	size_t i2 = 1;
	ssize_t right = main.size() - 1;
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (jacop.size() > i2 && idx[i] == jacop[i2] - 2)
			i2++;
		if (jacop.size() > i2)
			right = jacop[i2] * 2 - jacop[i2 - 1] - 2;
		if (right >= (ssize_t)main.size())
			right = main.size() - 1;
		binarySearch(main, pend, pairSize, right, idx[i]);
	}
	copyContainer(vec, main, pairSize);
}

void	PmergeMe::sortDeq( size_t pairSize )
{
		vecMap seqq(deq.size() / pairSize);

	if (seqq.size() < 2)
		return ;
	ssize_t k = 0;
	for (size_t i = 0; i < seqq.size(); i++)
	{
		seqq[i].assign(deq.begin() + k, deq.begin() + k + pairSize);
		k += pairSize;
	}
	for (size_t i = 0; i + 1 < seqq.size(); i += 2)
	{
		if (seqq[i][pairSize - 1] > seqq[i + 1][pairSize - 1])
			std::swap(seqq[i], seqq[i + 1]);
	}
	copyContainer(deq, seqq, pairSize);
	sortDeq(pairSize * 2);
	for (size_t i = 0, k = 0; i < seqq.size(); i++, k += pairSize)
		std::copy(deq.begin() + k, deq.begin() + k + pairSize, seqq[i].begin());
	deqMap main;
	deqMap pend;
	std::vector<unsigned int> idx;
	std::vector<ssize_t> jacop;
	jacop.push_back(1);
	main.push_back(seqq[0]);
	for (size_t i = 1, k = 2; i < seqq.size(); i += 2)
	{
		main.push_back(seqq[i]);
		if (i + 1 < seqq.size())
		{
			if (jacop.back() - 2 < (ssize_t)pend.size())
				jacop.push_back(getNextUn(k++, jacop.back()));
			pend.push_back(seqq[i + 1]);
		}
	}
	unsigned int prevJacop;
	unsigned int currJacop;
	k = 1;
	while (idx.size() < pend.size() && jacop.size() > 1)
	{
		prevJacop = jacop[k - 1];
		if (k < (ssize_t)jacop.size())
		{
			currJacop = jacop[k];
			while (currJacop > prevJacop)
			{
				if (pend.size() > currJacop - 2)
					idx.push_back(currJacop - 2);
				currJacop--;
			}
		}
		else
		{
			prevJacop = jacop[k - 1]++;
			while (idx.size() < pend.size())
			{
				idx.push_back(prevJacop - 2);
				prevJacop++;
			}
		}
		k++;
	}
	size_t i2 = 1;
	ssize_t right = main.size() - 1;
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (jacop.size() > i2 && idx[i] == jacop[i2] - 2)
			i2++;
		if (jacop.size() > i2)
			right = jacop[i2] * 2 - jacop[i2 - 1] - 2;
		if (right >= (ssize_t)main.size())
			right = main.size() - 1;
		binarySearch(main, pend, pairSize, right, idx[i]);
	}
	copyContainer(deq, main, pairSize);
}
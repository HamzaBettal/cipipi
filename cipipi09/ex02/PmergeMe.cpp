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
#include <cmath>
#include <cstddef>
#include <vector>
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

void	PmergeMe::saveData( int ac, char **av )
{
	this->vec.resize(ac - 1);

	for (int i = 1; i < ac; i++)
	{
		if (!std::isdigit(av[i][0]))
			throw "Error: require numbers only.";
		this->vec[i - 1] = std::atol(av[i]);
	}
}

unsigned int getNextUn(unsigned int n, unsigned int prev_Un)
{
	return (pow(2, n) - prev_Un);
}

void binarySearch( vecMap &main, vecMap &pend, size_t pairSize , size_t index )
{
	ssize_t left = 0;
	ssize_t right = main.size() - 1;
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

void	PmergeMe::recurSort( size_t pairSize )
{
	vecMap seqq(vec.size() / pairSize);

	if (seqq.size() < 2)
		return ;
	size_t k = 0;
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
	recurSort(pairSize * 2);
	k = 0;
	for (size_t i = 0; i < seqq.size(); i++, k += pairSize)
		std::copy(vec.begin() + k, vec.begin() + k + pairSize, seqq[i].begin());
	vecMap main;
	vecMap pend;
	//adding the minimest b to main container
	main.push_back(seqq[0]);
	for (size_t i = 1; i < seqq.size(); i += 2)
	{
		main.push_back(seqq[i]);
		if (i + 1 < seqq.size())
		{

			pend.push_back(seqq[i + 1]);
		}
	}
	for (size_t i = 0; i < pend.size(); i++)
	{

		binarySearch(main, pend, pairSize, i);
	}
	for (size_t i = 0; i < main.size(); i++)
	{
		for (size_t j = 0; j < main[i].size(); j++)
			std::cout << main[i][j] << " ";
		std::cout << "| ";
	}
	std::cout << '\n';
	copyContainer(vec, main, pairSize);
	return ;
};
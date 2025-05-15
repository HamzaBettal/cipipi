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
#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <utility>
#include <vector>

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
	this->vec = other.vec;
	this->deq = other.deq;
	return *this;
}

void PmergeMe::saveData( int ac, char **av )
{
	bool odd = false;
	if (ac % 2 == 0)
		odd = true;
	this->vec.resize(ac - 1);
	this->deq.resize(ac - 1);

	for (int i = 1; i < ac; i++)
	{
		if (!std::isdigit(av[i][0]))
			throw "Error: require numbers only.";
		this->deq[i - 1] = std::atoi(av[i]);
		this->vec[i - 1] = std::atoi(av[i]);
	}
	if (odd)
	{
		this->vec.push_back(-1);
		this->deq.push_back(-1);
	}
}

std::vector<std::vector<int> > PmergeMe::recurVec( size_t pairSize )
{
	std::vector<std::vector<int> > seqq(floor(vec.size() / pairSize));
	size_t k = 0;

	for (size_t i = 0; i < seqq.size(); i++)
	{
		seqq[i].assign(vec.begin() + k, vec.begin() + k + pairSize);
		k += pairSize;
		// std::cout << "["<< seqq[i][0] << ", " << seqq[i][1] << ", " << seqq[i][2] << ", " << seqq[i][3] << "]" << std::endl;
	}
	for (size_t i = 0; i + 1 < seqq.size(); i += 2)
	{
		int a = *std::max_element(seqq[i].begin(), seqq[i].end());
		int b = *std::max_element(seqq[i + 1].begin(), seqq[i + 1].end());
		std::cout << "a ==> " << a << std::endl;
		std::cout << "b ==> " << b << std::endl;
		if (a > b)
			std::swap(seqq[i], seqq[i + 1]);
	}
	k = 0;
	for (size_t i = 0; i < seqq.size(); i++)
	{
		std::copy(seqq[i].begin(), seqq[i].end(), vec.begin() + k);
		k += pairSize;
		// std::cout << "["<< seqq[i][0] << ", " << seqq[i][1] << ", " << seqq[i][2] << ", " << seqq[i][3] << "]" << std::endl;
	}
	std::cout << '[';
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ", ";
		if ((i + 1) % pairSize == 0 && i != 0)
			std::cout << "][";
	}
	std::cout << "]\n";
	if (pairSize >= vec.size() / 2)
		return seqq;
	recurVec(pairSize * 2);

	return seqq;
}

std::vector<std::pair<int, int> > PmergeMe::getPairs() //smallers in p.first
{
	std::vector<std::pair<int, int> > stock(vec.size() / 2);
	size_t j = 0;
	
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
		{
			stock[j].first = vec[i + 1];
			stock[j].second = vec[i];
		}
		else
		{
			stock[j].first = vec[i];
			stock[j].second = vec[i + 1];
		}
		// std::cout << "["<< stock[j].first << ", " << stock[j].second << "]";
		j++;
	}
	// std::cout << std::endl;
	return stock;
}

void PmergeMe::pairing()
{
	std::vector<std::pair<int, int> > stock = getPairs();
	
	size_t j = 0;
	for (size_t i = 0; i < stock.size(); i++)
	{
		vec[j] = stock[i].first;
		vec[j + 1] = stock[i].second;
		j += 2;
	}
	recurVec(2);

	// for (int i = 0; i < stock.size(); i++)
	// {
	// 	smallers[i] = stock[i].first;
	// 	largests[i] = stock[i].second;
	// }
}

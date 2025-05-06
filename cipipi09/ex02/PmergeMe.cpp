/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:59:28 by hbettal           #+#    #+#             */
/*   Updated: 2025/05/01 19:00:08 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
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

std::vector<std::vector<int> > &PmergeMe::recurVec( std::vector<std::vector<int> > sequence, size_t pairSize ) //smallers in p.first
{
	std::vector<std::vector<int> > seqq(vec.size() / pairSize);
	std::vector<int> pairLevel(pairSize);

	// std::vector<std::pair<int, int> > stock(vec.size() / 2);
	// size_t j = 0;
	
	// for (size_t i = 0; i < vec.size(); i += 2)
	// {
	// 	if (vec[i] > vec[i + 1])
	// 	{
	// 		stock[j].first = vec[i + 1];
	// 		stock[j].second = vec[i];
	// 	}
	// 	else
	// 	{
	// 		stock[j].first = vec[i];
	// 		stock[j].second = vec[i + 1];
	// 	}
	// 	// std::cout << "["<< stock[j].first << ", " << stock[j].second << "]"<< std::endl;
	// 	j++;
	// }
	// return stock;
}

std::vector<std::pair<int, int> > &PmergeMe::getPairs() //smallers in p.first
{
	
}

void PmergeMe::pairing()
{
	std::vector<std::vector<int> > stock = getPairs();
	// std::vector<int> smallers(stock.size());
	// std::vector<int> largests(stock.size());

	// for (int i = 0; i < stock.size(); i++)
	// {
	// 	smallers[i] = stock[i].first;
	// 	largests[i] = stock[i].second;
	// }
}

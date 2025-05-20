/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:59:36 by hbettal           #+#    #+#             */
/*   Updated: 2025/05/08 01:07:40 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
//(2^(k+1)+(-1)^k)/3

typedef std::vector<std::vector<unsigned int> > vecMap;
typedef std::vector<std::vector<unsigned int> > deqMap;
template <typename F, typename T>
void copyContainer( F &from, T &to, size_t pairSize )
{
	size_t k = 0;
	for (size_t i = 0; i < to.size(); i++, k += pairSize)
		std::copy(to[i].begin(), to[i].end(), from.begin() + k);
};

// template <typename Cont>
class PmergeMe
{
	private:
        std::vector<unsigned int> vec;
        std::deque<unsigned int> deq;

	public:
		void	is_it_sorted()
		{
			for(size_t i = 0; i < vec.size(); i++)
				if (i + 1 < vec.size())
					if (vec[i] > vec[i +1])
					{
						std::cout << "not sorted" << vec[i] << "/n";
					}
		};
		PmergeMe();
		PmergeMe( const PmergeMe &other );
		~PmergeMe();

		PmergeMe &operator=( const PmergeMe &other );
		
		void	saveData( int ac, char **av );
		void	recurSort( size_t pairSize );
};

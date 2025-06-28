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

#include <deque>
#include <iostream>
#include <vector>
#include <sys/time.h>

typedef std::vector<std::vector<unsigned int> > vecMap;
typedef std::vector<std::vector<unsigned int> > deqMap;
template <typename F, typename T>
void copyContainer( F &from, T &to, size_t pairSize )
{
	size_t k = 0;
	for (size_t i = 0; i < to.size(); i++, k += pairSize)
		std::copy(to[i].begin(), to[i].end(), from.begin() + k);
};

class PmergeMe
{
	private:
        std::vector<unsigned int> vec;
        std::deque<unsigned int> deq;
		ssize_t lenght;

	public:
		PmergeMe();
		PmergeMe( const PmergeMe &other );
		~PmergeMe();

		PmergeMe &operator=( const PmergeMe &other );
		
		void	saveVecData( int ac, char **av );
		void	saveDeqData( int ac, char **av );
		void	printData( int ac, char **av );
		void	sortVec( size_t pairSize );
		void	sortDeq( size_t pairSize );
};

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

typedef std::vector<std::vector<unsigned int> > mapp;

class PmergeMe
{
	private:
        std::vector<unsigned int> vec;
		std::deque<unsigned int> deq;
		
	public:
		PmergeMe();
		PmergeMe( const PmergeMe &other );
		~PmergeMe();

		PmergeMe &operator=( const PmergeMe &other );
		
		void	saveData( int ac, char **av );
		void	recurSort( size_t pairSize = 1 );
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:59:36 by hbettal           #+#    #+#             */
/*   Updated: 2025/05/01 18:59:55 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <deque>
#include <iostream>
#include <ratio>
#include <vector>
#include <utility>


class PmergeMe
{
	private:
        std::vector<int> vec;
		std::deque<int> deq;
		
	public:
		PmergeMe();
		PmergeMe( const PmergeMe &other );
		~PmergeMe();

		PmergeMe &operator=( const PmergeMe &other );
		
		void 							saveData( int ac, char **av );
		void 							pairing( void );
		std::vector<std::vector<int> > &getPairs();
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:17:22 by hbettal           #+#    #+#             */
/*   Updated: 2025/05/14 00:51:12 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <cmath>

class Span
{
	private:
		int				*data;
		unsigned int	size;
		unsigned int	index;

	public:
		Span( void );
		Span( unsigned int N );
		Span( const Span &other );
		~Span();

		Span &operator=( const Span &other );
		void addNumber( int num );
		unsigned int shortestSpan( void );
		unsigned int longestSpan( void );
        template<typename iter>
        void addRange( iter begin , iter end )
        {
        	size_t	dis = std::distance(begin, end);
        	if (dis + this->index > this->size)
        		throw std::out_of_range("out of range");
        	std::copy(begin, end, this->data + this->index);
        	this->index += dis;
        }
};

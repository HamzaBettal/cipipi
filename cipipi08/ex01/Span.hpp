/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:17:22 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/30 16:16:56 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>

class Span
{
	private:
		int				*data;
		unsigned int	size;
		unsigned int	curr;

	public:
		Span( void );
		Span( unsigned int N );
		Span( const Span &other );
		~Span();

		Span &operator=( const Span &other );
		void addNumber( int num );
		int shortestSpan( void );
		int longestSpan( void );
		template<typename iter>
		void addRange( iter begin , iter end )
		{
			size_t	s = std::distance(begin, end);
			if (s + this->curr > this->size)
				throw std::out_of_range("out of range");
			std::copy(begin, end, this->data + curr);
			curr += s;
		}
};
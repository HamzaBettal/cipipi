/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:17:20 by hbettal           #+#    #+#             */
/*   Updated: 2025/05/14 00:46:52 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : data(NULL), size(0), index(0)
{
}

Span::Span( unsigned int N ) : data(new int[N]), size(N), index(0)
{
}

Span::Span( const Span &other )
{
	*this = other;
}

Span &Span::operator=( const Span &other )
{
	if (this != &other)
	{
        delete[] data;
		data = new int [other.size];
		for (unsigned int i = 0; i < other.size; i++)
			data[i] = other.data[i];
	}
	return *this;
}

Span::~Span( void )
{
	delete[] data;
}

void Span::addNumber( int num )
{
	if (index >= size)
		throw std::out_of_range("out of range");
	data[index] = num;
	index++;
}

unsigned int Span::shortestSpan()
{
	if (index < 2)
		throw std::runtime_error("At least two numbers are required");
	std::sort(data, data + size);
	long minspan = std::numeric_limits<int>::max();

	for (unsigned int i = 1; i < size; i++)
	{
		int diff = data[i] - data[i - 1];
		if (diff < minspan)
			minspan = diff;
	}
	return (std::abs(minspan));
}

unsigned int Span::longestSpan()
{
	if (index < 2)
		throw std::runtime_error("At least two numbers are required");
	return (std::abs(*std::max_element(data, data + size) - *std::min_element(data, data + size)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:17:20 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/21 16:19:27 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : data(NULL), size(0), curr(0)
{
}

Span::Span( unsigned int N ) : data(new int[N]), size(N), curr(0)
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
	if (curr >= size)
		throw std::out_of_range("out of range");
	data[curr] = num;
	curr++;
}

int Span::shortestSpan()
{
	if (curr < 2)
		throw std::runtime_error("At least two numbers are required");
	std::sort(data, data + size);
	int minspan = std::numeric_limits<int>::max();

	for (unsigned int i = 1; i < size; i++)
	{
		int diff = data[i] - data[i - 1];
		if (diff < minspan)
			minspan = diff;
	}
	return (minspan);
}

int Span::longestSpan()
{
	if (curr < 2)
		throw std::runtime_error("At least two numbers are required");
	return (*std::max_element(data, data + size) - *std::min_element(data, data + size));
}

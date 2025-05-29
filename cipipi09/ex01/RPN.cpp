/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:07:30 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/25 23:54:42 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <cstddef>

RPN::RPN()
{}

RPN::RPN( const RPN &other )
{
	*this = other;
}

RPN::~RPN()
{}

RPN &RPN::operator=( const RPN &other )
{
	this->stack = other.stack;
	return *this;
}

bool	RPN::isOperator( const char c )
{
	return (c == '*' || c == '/' || c == '+' || c == '-');
}

void	RPN::calcule( const char op )
{
	double a, b;
	if (stack.size() < 2)
		throw "Error";
	b = stack.top();
	stack.pop();
	a = stack.top();
	stack.pop();
	switch (op)
	{
		case '+':
			stack.push(a + b);
			return ;
		case '-':
			stack.push(a - b);
			return ;
		case '*':
			stack.push(a * b);
			return ;
		case '/':
			if (a == 0)
				throw "Error: Division by zero!";
			stack.push(a / b);
	}
}

void	RPN::act( const std::string &av )
{
	for (size_t i = 0; i < av.size(); i++)
	{
		if (std::isdigit(av[i]))
		{
			stack.push(av[i] - '0');
		}
		if (isOperator(av[i]))
			calcule(av[i]);
	}
	if (stack.size() > 1)	
		throw "Error";
	std::cout << stack.top() << std::endl;
}

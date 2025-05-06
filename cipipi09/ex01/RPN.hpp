/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:03:20 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/25 23:30:02 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>


class RPN
{
	private:
        std::stack<int> stack;
		
	public:
		RPN();
		RPN( const RPN &other );
		~RPN();

		RPN &operator=( const RPN &other );
		
		static bool	isOperator( const char c );
		void	act( const std::string &av );
		void	calcule( const char op );
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:34:10 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/25 23:43:46 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

bool    isValid( const char c )
{
    return (std::isdigit(c) || RPN::isOperator(c) || c == ' ');
}

int main(int ac, char **av)
{
    RPN rpn;
    int i = 0;

    if (ac != 2)
    {
        std::cerr << "Error: Invalid number of argements." << std::endl;
        return 1;
    }
    while (av[1][i])
    {
        if (!isValid(av[1][i]))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        i++;
    }
    try
    {
        rpn.act(av[1]);
    }
    catch ( char const *e )
    {
        std::cerr <<  e << std::endl;
    }
}
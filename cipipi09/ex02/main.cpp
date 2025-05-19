/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:34:10 by hbettal           #+#    #+#             */
/*   Updated: 2025/05/01 18:04:08 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe sorter;

    try
    {
        if (ac <= 2)
            throw "Error: you need at least 2 numbers.";
        sorter.saveData(ac, av);
        sorter.recurSort();
    }
    catch ( char const *e )
    {
        std::cerr << e << std::endl;
    }
}
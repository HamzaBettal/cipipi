/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:03:09 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/15 10:45:14 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] != '\0')
        ScalarConverter::convert(av[1]);
    else
        std::cerr << "Error: Invalid arguments" << std::endl;
    return 0;
}
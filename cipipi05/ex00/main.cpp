/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:15 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/10 13:05:21 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main()
{
    try
    {
        Bureaucrat object("name", 1);
        std::cout << object;
        object.decreaseGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

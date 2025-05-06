/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:47:32 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/25 15:34:43 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i;
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << std::endl;
        arr[6] = 42;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

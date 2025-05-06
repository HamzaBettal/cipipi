/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:29:47 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/24 15:32:40 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void print(int num)
{
    std::cout << num << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    iter(arr, 6, print);
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:28:43 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/30 16:03:10 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T data, int N)
{
    if (std::find(data.begin(), data.end(), N) != data.end())
        std::cout << "Found" << std::endl;
    else
        throw std::out_of_range("Not found");
}

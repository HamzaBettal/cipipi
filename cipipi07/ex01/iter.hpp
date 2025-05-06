/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:08:09 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/24 15:23:35 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T, typename F>
void iter(T *arr, size_t size, F fun)
{
    for (size_t i = 0; i < size; i++)
        fun(arr[i]);
}
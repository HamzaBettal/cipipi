/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:48:09 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/13 12:51:44 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    data.n = 42;
    data.s1 = "Hello";
    data.s2 = "World";

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << ptr->n << std::endl;
    std::cout << ptr->s1 << std::endl;
    std::cout << ptr->s2 << std::endl;

    return 0;
}
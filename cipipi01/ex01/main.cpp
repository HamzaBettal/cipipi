/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:17:02 by hbettal           #+#    #+#             */
/*   Updated: 2024/11/29 15:30:48 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int i = 5;
    int j = 0;
    Zombie *horde = ZombieHorde(i, "Bob");

    std::cout << "exampleee :" << std::endl;
    while (j < i)
    {
        horde[j].announce();
        j++;
    }
    delete[] horde;
}

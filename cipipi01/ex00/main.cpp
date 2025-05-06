/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:17:05 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/01 20:21:04 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "=====heap example=====\n";

    Zombie *heapZombie = newZombie("BoB");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "\n\n=====stack example=====\n";
    randomChump("machi BoB");
}

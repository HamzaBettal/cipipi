/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:16:52 by hbettal           #+#    #+#             */
/*   Updated: 2024/11/26 18:18:10 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *ZombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    Zombie  *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        horde[i].setname(name);
    return (horde);
}

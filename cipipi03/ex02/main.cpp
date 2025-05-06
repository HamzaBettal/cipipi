/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:32:15 by hbettal           #+#    #+#             */
/*   Updated: 2025/01/12 16:31:09 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap b("link");
	ClapTrap a(b);
	ClapTrap *c = new ScavTrap("zelda");

	a.attack("zombie");
	b.attack("enemy");
	c->attack("test");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:19:56 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/09 13:37:32 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private :
		std::string _name;

	public :
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap &other );
		~DiamondTrap();
		
		DiamondTrap	&operator=( DiamondTrap &other );
		
		void		whoAmI();
};
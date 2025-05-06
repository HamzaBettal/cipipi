/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:50:28 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/09 14:17:12 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap( std::string _name );
		ScavTrap( ScavTrap &other );
		~ScavTrap();
		
		ScavTrap &operator=( ScavTrap &other );
		
		void	attack( const std::string& target );
		void	guardGate( void );
};

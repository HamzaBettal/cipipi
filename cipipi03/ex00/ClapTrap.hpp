/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:32:13 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/08 22:44:46 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
	private :
		std::string	_name;
		int			hitPoint;
		int			energyPoint;
		int			attackDamage;
		
	public :
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( ClapTrap &other );
		~ClapTrap( void );
		
		ClapTrap	&operator=( ClapTrap &other );
		
		void	attack( const std::string &target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:37:31 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/08 22:53:10 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default FragTrap Constructor Called\n";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor Called\n";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap( FragTrap &other ) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor Called\n";
}

FragTrap &FragTrap::operator=( FragTrap &other )
{
	std::cout << "FragTrap Copy Assignment Operator Called\n"; 
	this->_name = other._name;
	this->hitPoint = other.hitPoint;
	this->energyPoint = other.energyPoint;
	this->attackDamage = other.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called\n";
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "High Fives\n";
}

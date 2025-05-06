/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:10:07 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/08 22:53:10 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap Constructor Called\n";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor Called\n";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap( ScavTrap &other ) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Assingment Called\n";
}

ScavTrap &ScavTrap::operator=( ScavTrap &other )
{
	std::cout << "ScavTrap Copy Assignment Operator Called\n"; 
	this->_name = other._name;
	this->hitPoint = other.hitPoint;
	this->energyPoint = other.energyPoint;
	this->attackDamage = other.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

void	ScavTrap::attack( const std::string& target )
{
	std::cout << "ScavTrap " + _name + " attacks " + target + ", causing " << attackDamage << " point of damage!\n";
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is now in Gatekeeper mode\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:32:10 by hbettal           #+#    #+#             */
/*   Updated: 2025/01/12 16:12:48 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "Default Constructor Called\n";
}

ClapTrap::ClapTrap( ClapTrap &other ) : _name(other._name), hitPoint(other.hitPoint), energyPoint(other.energyPoint), attackDamage(other.attackDamage)
{
	std::cout << "Copy Constructor Called\n";
}

ClapTrap::ClapTrap( std::string name ) : _name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap Constructor Called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called\n";
}

ClapTrap    &ClapTrap::operator=( ClapTrap &other )
{
	std::cout << "Copy assignment operator called\n"; 
	this->_name = other._name;
	this->hitPoint = other.hitPoint;
	this->energyPoint = other.energyPoint;
	this->attackDamage = other.attackDamage;
	return (*this);
}

void        ClapTrap::attack( const std::string &target )
{
	std::cout << "ClapTrap " + _name + " attacks " + target + ", causing " << attackDamage << " point of damage!\n";
}

void		ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " + _name + " take " << amount << " point of damage, now the health is " << hitPoint - amount << ".\n";
}

void		ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap " + _name + " repaire " << amount << " point of energy, now the energy is " << amount + energyPoint << ".\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:08:54 by hbettal           #+#    #+#             */
/*   Updated: 2025/03/13 08:59:52 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	this->_name = "Default";
	this->count = 0;
	this->onfloor = NULL;
	this->items = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->items[i] = NULL;
}

Character::Character( std::string name )
{
	this->_name = name;
	this->count = 0;
	this->onfloor = NULL;
	this->items = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->items[i] = NULL;
}

Character::Character( const Character &other )
{
	this->items = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->items[i] = NULL;
	*this = other;
}

Character::~Character()
{
	int i;
	for (i = 0; i < 4; i++)
		delete this->items[i];
	delete[] this->items;
	for (i = 0; i < this->count; i++)
		delete this->onfloor[i];
	delete[] this->onfloor;
}

Character &Character::operator=( const Character &other )
{
	if (this != &other)
	{
		this->_name = other._name;
		this->count = other.count;
		for (int i = 0; i < 4; i++)
		{
			delete this->items[i];
			if (other.items[i])
				this->items[i] = other.items[i]->clone();
			else
			 	this->items[i] = NULL;
		}
	}
	return *this;
}

std::string const	&Character::getName( void ) const
{
	return this->_name;
}

void	Character::equip(AMateria *m)
{
	int i = 0;
	
	while (this->items[i])
	{
		if (this->items[i] == m)
			return ;
		i++;
	}
	if (i < 4)
	{
		this->items[i] = m;
		for (int i = 0; i < this->count; i++)
		{
			if (this->onfloor[i] == m)
			{
				this->onfloor[i] = NULL;
				return ;
			}
		}
	}
	else
	 	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		int i;
		AMateria **tmp = new AMateria*[++this->count];

		for (i = 0; i < this->count - 1; i++)
			tmp[i] = this->onfloor[i];
		tmp[i] = this->items[idx];
		this->items[idx] = NULL;
		
		delete[] this->onfloor;

		this->onfloor = tmp;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->items[idx])
		this->items[idx]->use(target);
}
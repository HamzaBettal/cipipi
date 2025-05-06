/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:23:49 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 17:20:46 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice( const Ice &other )
{
	*this = other;
}

Ice::~Ice() {}

Ice &Ice::operator=( const Ice &other )
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AMateria *Ice::clone( void ) const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

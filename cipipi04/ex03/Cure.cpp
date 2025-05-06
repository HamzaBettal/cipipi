/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:17:11 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 17:20:20 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure( const Cure &other )
{
	*this = other;
}

Cure::~Cure()
{
}

Cure &Cure::operator=( const Cure &other )
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AMateria *Cure::clone( void ) const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

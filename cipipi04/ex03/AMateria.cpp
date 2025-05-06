/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:10:29 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 17:18:58 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria( std::string const &type ) : _type(type)
{
}

AMateria::AMateria( const AMateria &other )
{
    *this = other;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=( const AMateria &other )
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

std::string const &AMateria::getType( void ) const
{
    return (this->_type);
}

void AMateria::use( ICharacter& target )
{
    std::cout << target.getName() << " is scared ... nothing happend\n";
}

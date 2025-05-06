/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:42:38 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/13 12:48:06 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{}

Serializer::Serializer( Serializer const &src )
{
    *this = src;
}

Serializer::~Serializer()
{}

Serializer &Serializer::operator=( Serializer const &rhs )
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

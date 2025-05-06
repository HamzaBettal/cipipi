/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:54:13 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 17:23:15 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
    this->materials = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->materials[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource &other )
{
    this->materials = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->materials[i] = NULL;
    *this = other;
}

MateriaSource &MateriaSource::operator=( const MateriaSource &other )
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete this->materials[i];
            if (other.materials[i])
                this->materials[i] = other.materials[i]->clone();
            else
                this->materials[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->materials[i];
    delete[] this->materials;
}

void MateriaSource::learnMateria( AMateria *type )
{
    int i = 0;
    while (this->materials[i])
    {
        if (this->materials[i] == type)
            return;
        i++;
    }
    if (i < 4)
        this->materials[i] = type;
    else
        delete type;
}

AMateria *MateriaSource::createMateria( std::string const &type )
{
    int i = 0;

    while (this->materials[i])
    {
        if (type == this->materials[i]->getType())
            return this->materials[i]->clone();
        i++;
    }
    return 0;
}

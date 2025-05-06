/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:24:02 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 17:02:22 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->idea = new Brain();
    type = "Default";
    std::cout << "Default Contructor of Animal Called\n";
}

Animal::Animal( const Animal &other )
{
    *this = other;
    std::cout << "Copy Contructor of Animal Called\n";
}

Animal &Animal::operator=( const Animal &other )
{
    if (this != &other)
    {
        this->type = other.type;
        delete this->idea;
        this->idea = new Brain(*other.idea);
    }
    std::cout << "Copy Assignment Operator of Animal Called\n";
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Default Decontructor of Animal Called\n";
    delete this->idea;
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "Does not have a sound\n";
}

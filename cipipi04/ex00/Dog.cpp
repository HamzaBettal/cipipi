/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:22:07 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 16:47:55 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Default Contructor of Dog Called\n";
}

Dog::Dog( const Dog &other ) : Animal( other )
{
    std::cout << "Copy Contructor of Dog Called\n";
}

Dog &Dog::operator=( const Dog &other )
{
    std::cout << "Copy Assignment Operator of Dog Called\n";
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Default Contructor of Dog Called\n";
}

void    Dog::makeSound() const
{
    std::cout << "Bark\n";
}
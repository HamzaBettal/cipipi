/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:39:03 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 16:46:31 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Default Contructor of Cat Called\n";
}

Cat::Cat( const Cat &other ) : Animal( other )
{
    std::cout << "Copy Contructor of Cat Called\n";
}

Cat &Cat::operator=( const Cat &other )
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Copy Assignment Operator of Cat Called\n";
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Default Contructor of Cat Called\n";
}

void    Cat::makeSound() const
{
    std::cout << "Meow\n";
}

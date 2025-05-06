/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:43:19 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 05:49:55 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor Called\n";
}

Brain::Brain( const Brain &other )
{
    std::cout << "Brain Copy Constructor Called\n";
    *this = other;
}

Brain &Brain::operator=( const Brain &other )
{
    std::cout << "Copy Assignment Operator Called\n";
    if (this != &other)
    {
        for (int i = 0; i < 200 ; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called\n";    
}

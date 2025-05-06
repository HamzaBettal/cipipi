/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:07:39 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 05:45:35 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected :
        std::string type;
        Brain       *idea;

    public :
        Animal( void );
        virtual ~Animal();
        Animal( const Animal &other );
    
        Animal &operator=( const Animal &other );

        std::string     getType() const;
        virtual void    makeSound() const;
};

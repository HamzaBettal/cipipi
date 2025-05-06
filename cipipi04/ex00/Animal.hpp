/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:07:39 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 17:00:12 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
    protected :
        std::string type;

    public :
        Animal( void );
        Animal( const Animal &other );
        ~Animal();
    
        Animal &operator=( const Animal &other );

        std::string     getType() const;
        virtual void    makeSound() const;
};

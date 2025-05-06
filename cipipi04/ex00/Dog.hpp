/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:13:25 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 16:47:21 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog( void );
        Dog( const Dog &other );
        ~Dog();

        Dog &operator=( const Dog &other );

        void makeSound( void ) const;
};

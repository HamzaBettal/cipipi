/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:14:56 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 05:45:07 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat( void );
        Cat( const Cat &other );
        ~Cat();

        Cat &operator=( const Cat &other );

        void makeSound( void ) const;
};

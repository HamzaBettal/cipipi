/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:09:16 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 03:32:33 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice( void );
        Ice( const Ice &other );
        ~Ice();

        Ice &operator=( const Ice &other );
        
        AMateria*   clone( void ) const;
        void        use(ICharacter &target);
};

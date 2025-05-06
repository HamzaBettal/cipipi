/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:29:12 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 05:46:15 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
    public :
        std::string ideas[100];
        
        Brain( void );
        Brain( const Brain &other );
        ~Brain();

        Brain &operator=( const Brain &other );
};

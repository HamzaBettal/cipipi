/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:42:41 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/15 11:42:46 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef struct Data
{
    int n;
    std::string s1;
    std::string s2;
} Data;

class Serializer
{
    Serializer( void );
    public:
        Serializer( Serializer const &src );
        ~Serializer();
        
        Serializer &operator=( Serializer const &rhs );

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
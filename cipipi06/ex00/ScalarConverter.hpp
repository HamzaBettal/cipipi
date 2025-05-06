/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:43:01 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/15 12:26:59 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

enum type
{
    _CHAR,
    _INT,
    _FLOAT,
    _DOUBLE,
    _NAN,
    _PINF,
    _NINF,
    _INVALID
};

class ScalarConverter
{
    ScalarConverter( void );
    public:
        ScalarConverter( ScalarConverter const &src );
        ~ScalarConverter();

        ScalarConverter &operator=( ScalarConverter const &rhs );
        
        static void convert( std::string str );
};

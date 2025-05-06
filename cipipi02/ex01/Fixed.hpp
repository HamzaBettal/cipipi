/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:57:33 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/07 02:16:02 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed 
{
	private :
		int					number;
		static const int	bits = 8;
	public :
		Fixed( void );
		Fixed( int raw );
		Fixed( float raw );
		Fixed( const Fixed &other );
		Fixed &operator=( const Fixed &other );
		~Fixed();
		int     getRawBits( void ) const;
		void    setRawBits( int const raw);
		float   toFloat( void ) const;
		int     toInt( void ) const;
};

std::ostream &operator<<( std::ostream &out, const Fixed &other );

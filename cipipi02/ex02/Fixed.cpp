/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:58:04 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/09 15:25:34 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->number = 0;
}

Fixed::Fixed( const Fixed &other ) : number(other.number)
{
}

Fixed::Fixed( const int raw ) : number(roundf(raw << Fixed::bits))
{
}

Fixed::Fixed( const float raw ) : number(roundf(raw * (1 << Fixed::bits)))
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::min( Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed &Fixed::max( Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

Fixed &Fixed::operator=( const Fixed &other )
{
	this->number = other.number;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, const Fixed &other )
{
    out << other.toFloat();
    return (out);
}

bool Fixed::operator<( const Fixed &other ) const
{
	return (this->number < other.number);
}

bool Fixed::operator<=( const Fixed &other ) const
{
	return (this->number <= other.number);
}

bool Fixed::operator>( const Fixed &other ) const
{
	return (this->number > other.number);
}

bool Fixed::operator>=( const Fixed &other ) const
{
	return (this->number >= other.number);
}

bool Fixed::operator==( const Fixed &other ) const
{
	return (this->number == other.number);
}

bool Fixed::operator!=( const Fixed &other ) const
{
	return (this->number != other.number);
}

Fixed Fixed::operator+( const Fixed &other )
{
	Fixed	tmp = *this;
	
	tmp.number += other.number;
	return (tmp);
}

Fixed Fixed::operator-( const Fixed &other )
{
	Fixed	tmp = *this;
	
	tmp.number -= other.number;
	return (tmp);
}

Fixed Fixed::operator*( const Fixed &other ) // a=1; b=2; a = (a + b) * a
{
	Fixed	tmp = *this;
	
	tmp.number *= other.toFloat();
	return (tmp);
}

Fixed Fixed::operator/( const Fixed &other )
{
	Fixed	tmp = *this;
	
	tmp.number /= other.toFloat();
	return (tmp);
}

Fixed Fixed::operator++( int )
{
	Fixed tmp = *this;
	this->number += 1;
	return (tmp);
}

Fixed &Fixed::operator++()
{
	this->number += 1;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed tmp = *this;
	this->number -= 1;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->number -= 1;
	return (*this);
}

int Fixed::getRawBits() const
{
	return (this->number);
}

void Fixed::setRawBits( int const raw )
{
	this->number = raw;
}

float Fixed::toFloat() const
{
    return ((float)this->number / (1 << Fixed::bits));
}

int Fixed::toInt() const
{
    return (number / (1 << Fixed::bits));
}

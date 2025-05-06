/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:08:55 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/07 01:55:53 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{}

Point::~Point()
{
}

Point &Point::operator=( const Point &other )
{
	(void)other;
	return (*this);
}

bool Point::operator==( const Point &other ) const
{
	return (this->getX() == other.getX() && this->getY() == other.getY());
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:37:48 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/07 02:17:46 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float   area( Point a, Point b, Point c )
{
	Fixed   Area;

	Area = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
	return (abs(Area.toFloat()) / 2);
}

bool    bsp( Point const a, Point const b, Point const c, Point const point )
{
	float   triangle, triangle1, triangle2, triangle3;
    
    if (!area(a, b, point) || (a == point || b == point || c == point))
        return false;
	triangle = area(a, b, c);
	triangle1 = area(point, b, c);
	triangle2 = area(a, point, c);
	triangle3 = area(a, b, point);

	return (triangle == triangle1 + triangle2 + triangle3);
}
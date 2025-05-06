/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:57:41 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/07 02:03:35 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point a(0, 0);
	Point b(2, 0);
	Point c(1, 1);
	Point p(1, 0.9);

	if (bsp(a, b, c, p))
		std::cout << "the point is inside the triangle" << std::endl;
	else
		std::cout << "the point is outside the triangle" << std::endl;
	return 0;
}

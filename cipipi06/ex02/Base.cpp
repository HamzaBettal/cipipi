/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:56:41 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/15 12:25:39 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;

    if (!random)
        return (new A);
    else if (random == 1)
        return (new B);
    return (new C);
}

void identify_from_pointer(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "pointer belong to A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "pointer belong to B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "pointer belong to C" << std::endl;
    else
        std::cout << "pointer is not belong to A, B or C" << std::endl;
}

void identify_from_reference(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "reference belong to A" << std::endl;
    }
    catch (std::bad_cast)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "reference belong to B" << std::endl;
        }
        catch (std::bad_cast)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "reference belong to C" << std::endl;
            }
            catch (std::bad_cast)
            {
                std::cout << "reference is not belong to A, B or C" << std::endl;
            }
        }
    }
}

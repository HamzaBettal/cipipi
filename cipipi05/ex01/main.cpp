/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:15 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/09 16:24:09 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <exception>

int main()
{
    try
    {
        Bureaucrat  b("seller", 100);
        Form        f("sell form", 100, 50);

        f.beSigned(b);
        f.signForm(b);
        std::cout << f << '\n';
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

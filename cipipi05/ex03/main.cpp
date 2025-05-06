/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:15 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/10 20:51:44 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <exception>
#include <iostream>

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm *rrf;
        AForm *ppf;
        AForm *scf;
        AForm *form;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        form = someRandomIntern.makeForm("random form", "Bender");
        std::cout << "hereeee!" << std::endl;
        delete rrf;
        delete ppf;
        delete scf;
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

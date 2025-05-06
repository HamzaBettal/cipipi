/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:15 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/09 16:16:54 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        ShrubberyCreationForm scf("home");
        PresidentialPardonForm ppf("Bender");
        RobotomyRequestForm rrf("Bender");
        
        Bureaucrat b("Bureaucrat", 1);
        // Bureaucrat b2("Bureaucrat2", 150);
        // Bureaucrat b3("Bureaucrat3", 75);

        scf.beSigned(b);
        ppf.beSigned(b);
        rrf.beSigned(b);
        
        b.executeForm(scf);
        b.executeForm(ppf);
        b.executeForm(rrf);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
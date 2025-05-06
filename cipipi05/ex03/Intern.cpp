/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:19:57 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/10 21:15:38 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <string>

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

AForm *Intern::ShrubberyCreation( const std::string &target )
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::RobotomyRequest( const std::string &target )
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::PresidentialPardon( const std::string &target )
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*form[3])( const std::string& ) = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};

    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*form[i])(target);
        }
    }
    throw Intern::FormNotFoundException();
    return NULL;
}

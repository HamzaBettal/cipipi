/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:17:55 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/10 21:14:06 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();
        Intern &operator=(const Intern &src);

        AForm *ShrubberyCreation( const std::string &target );
        AForm *RobotomyRequest( const std::string &target );
        AForm *PresidentialPardon( const std::string &target );

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form not found");
                }
        };
        AForm *makeForm(std::string formName, std::string target);
};

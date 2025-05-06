/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:49:08 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/08 16:10:12 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string type;
    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( const std::string &type );
        ShrubberyCreationForm( const ShrubberyCreationForm &other );
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=( const ShrubberyCreationForm &other );

        void    execute( Bureaucrat const & executor ) const;
};

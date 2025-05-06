/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:45:46 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/08 16:12:45 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string type;
    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( const std::string &type );
        PresidentialPardonForm( const PresidentialPardonForm &other );
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=( const PresidentialPardonForm &other );

        void    execute( Bureaucrat const & executor ) const;
};

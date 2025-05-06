/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:49:04 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/08 16:10:00 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string type;
    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( const std::string &type );
        RobotomyRequestForm( const RobotomyRequestForm &other );
        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=( const RobotomyRequestForm &other );

        void    execute( Bureaucrat const & executor ) const;
};

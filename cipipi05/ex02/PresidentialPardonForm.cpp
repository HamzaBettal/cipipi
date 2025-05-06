/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:43:35 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/09 16:50:55 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), type("default")
{
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &typee ) : AForm("PresidentialPardonForm", 25, 5), type(typee)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ) : type(other.type)
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &other )
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void    PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else if (!this->signCheck())
        throw AForm::FormNotSignedException();
    else
    {
        std::cout << this->type << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}

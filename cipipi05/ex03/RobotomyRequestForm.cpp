/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:43:33 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/08 16:12:13 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), type("default")
{
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &typee ) : AForm("RobotomyRequestForm", 72, 45), type(typee)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) : type(other.type)
{
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other )
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void    RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else if (!this->signCheck())
        throw AForm::FormNotSignedException();
    else
    {
        bool   success = rand() % 2;
        std::cout << "Drilling noises" << std::endl;
        if (success)
            std::cout << this->type << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->type << " robotomization failed" << std::endl;
    }
}

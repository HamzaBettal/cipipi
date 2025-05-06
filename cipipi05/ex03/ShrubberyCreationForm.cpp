/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:43:31 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/08 14:58:47 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137), type("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &typee ) : AForm("ShrubberyCreationForm", 145, 137), type(typee)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : type(other.type)
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void    ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else if (!this->signCheck())
        throw AForm::FormNotSignedException();
    else
    {
        std::ofstream   file;
        file.open(this->type + "_shrubbery");
        if (!file.is_open())
            std::cerr << "Error: file not open" << std::endl;
        file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
        file.close();
    }
}

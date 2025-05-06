/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:07:02 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/10 13:04:38 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1)
{
}

Bureaucrat::Bureaucrat( const std::string name, const int grade ) : _name(name), _grade(grade)
{
    if (this->_grade > 150)
        throw  Bureaucrat::GradeTooLowException();
    else if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _name(other._name)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other )
{
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string    Bureaucrat::getName() const
{
    return this->_name;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade cant be more than 1!";  
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade cant be less than 150!";
}

int    Bureaucrat::getGrade() const
{
    return this->_grade;
}

void    Bureaucrat::increaseGrade()
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}
   
void    Bureaucrat::decreaseGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executes " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " cant execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}
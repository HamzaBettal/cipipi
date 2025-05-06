/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:21:55 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/09 16:19:32 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <ostream>

Form::Form( void ) : _name("Default"), isSigned(false), gradeToSign(75), gradeToExec(50)
{
	if (this->gradeToExec > 150 || this->gradeToSign > 150)
		throw Form::GradeTooLowException();
	else if (this->gradeToExec < 1 || this->gradeToSign < 1)
		throw Form::GradeTooHighException();
}

Form::Form( const std::string name, const int gradeToS, const int gradeToEx ) : _name(name), isSigned(false), gradeToSign(gradeToS), gradeToExec(gradeToEx)
{
}

Form::Form( const Form &other ) :  _name(other._name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
}

Form &Form::operator=( const Form &other )
{
	(void)other;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, const Form &other )
{
	out << "name: " + other.getName() + ", grade to sign: " << other.getGradeToSign();
	out << ", grade to execute: " << other.getGradeToExec() << ", sign status: ";
	if (other.signCheck())
		out << "signed";
	else
		out << "not signed";
	return out;
}

Form::~Form()
{
}

std::string    Form::getName( void ) const
{
	return this->_name;
}

int Form::getGradeToExec( void ) const
{
	return this->gradeToExec;
}

int Form::getGradeToSign( void ) const
{
	return this->gradeToSign;
}

bool Form::signCheck( void ) const
{
	return this->isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade cant be more than 1!";  
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade cant be less than 150!";
}

void Form::beSigned( const Bureaucrat &other )
{
	if (this->gradeToSign >= other.getGrade())
		this->isSigned = true;
}

void Form::signForm( const Bureaucrat &other )
{
	if (this->isSigned)
		std::cout << other.getName() + " signed " + this->_name << std::endl;
	else
	 	std::cout << other.getName() + " couldn’t sign " + this->_name + " because the Bureaucrat's not in the mood to" << std::endl;
}

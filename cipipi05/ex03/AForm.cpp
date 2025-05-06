/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:21:55 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/19 14:42:28 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <ostream>

AForm::AForm( void ) : _name("Default"), isSigned(false), gradeToSign(75), gradeToExec(50)
{
	if (this->gradeToExec > 150 || this->gradeToSign > 150)
		throw AForm::GradeTooLowException();
	else if (this->gradeToExec < 1 || this->gradeToSign < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm( const std::string name, const int gradeToS, const int gradeToEx ) : _name(name), isSigned(false), gradeToSign(gradeToS), gradeToExec(gradeToEx)
{
}

AForm::AForm( const AForm &other ) :  _name(other._name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
}

AForm &AForm::operator=( const AForm &other )
{
	(void)other;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, const AForm &other )
{
	out << "name: " + other.getName() + ", grade to sign: " << other.getGradeToSign();
	out << ", grade to execute: " << other.getGradeToExec() << ", sign status: ";
	if (other.signCheck())
		out << "signed";
	else
		out << "not signed";
	return out;
}

AForm::~AForm()
{
}

std::string    AForm::getName( void ) const
{
	return this->_name;
}

int AForm::getGradeToExec( void ) const
{
	return this->gradeToExec;
}

int AForm::getGradeToSign( void ) const
{
	return this->gradeToSign;
}

bool AForm::signCheck( void ) const
{
	return this->isSigned;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade cant be more than 1!";  
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade cant be less than 150!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed!";
}

void AForm::beSigned( const Bureaucrat &other )
{
	if (this->gradeToSign >= other.getGrade())
		this->isSigned = true;
}

void AForm::signForm( const Bureaucrat &other )
{
	if (this->isSigned)
		std::cout << other.getName() + " signed " + this->_name << std::endl;
	else
	 	std::cout << other.getName() + " couldn’t sign " + this->_name + " because the Bureaucrat's not in the mood to" << std::endl;
}

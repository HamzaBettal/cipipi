/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:17:27 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/09 16:47:38 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <ostream>

class AForm
{
	private:
		const std::string   _name;
		bool                isSigned;
		const int			gradeToSign;
		const int			gradeToExec;
		
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		
		AForm();
		AForm( const std::string name, const int gradeToS, const int gradeToEx );
		AForm( const AForm &other );
		virtual ~AForm();
		
		AForm &operator=( const AForm &other );
		//getters
		std::string	getName( void ) const;
		bool		signCheck( void ) const;
		int			getGradeToSign( void ) const;
		int			getGradeToExec( void ) const;
		
		void beSigned( const Bureaucrat &other );
		void signForm( const Bureaucrat &other );
		virtual void execute( Bureaucrat const &executor ) const = 0;
};

std::ostream &operator<<( std::ostream &out, const AForm &other );

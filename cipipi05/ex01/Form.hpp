/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:17:27 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/09 16:47:32 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <ostream>

class Form
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
		
		Form();
		Form( const std::string name, const int gradeToS, const int gradeToEx );
		Form( const Form &other );
		~Form();
		
		Form &operator=( const Form &other );
		//getters
		std::string	getName( void ) const;
		bool		signCheck( void ) const;
		int			getGradeToSign( void ) const;
		int			getGradeToExec( void ) const;
		
		void beSigned( const Bureaucrat &other );
		void signForm( const Bureaucrat &other );
};

std::ostream &operator<<( std::ostream &out, const Form &other );

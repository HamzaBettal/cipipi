/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:48 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/10 13:04:15 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

class   Bureaucrat
{
	private:
		const std::string   _name;
		int                 _grade;
		
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

		Bureaucrat();
		Bureaucrat( const std::string name, const int grade );
		Bureaucrat( const Bureaucrat &other );
		~Bureaucrat();

		Bureaucrat &operator=( const Bureaucrat &other );
		
		int			getGrade( void ) const;
		std::string	getName( void ) const;
		void		increaseGrade();
		void		decreaseGrade();
};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
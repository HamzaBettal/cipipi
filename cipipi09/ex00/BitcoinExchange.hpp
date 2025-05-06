/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:34:08 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/25 16:22:51 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>


class BitcoinExchange
{
	private:
		typedef std::map<std::string, std::string> t_data;
		t_data data;
	public:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange &other );
		~BitcoinExchange();

		BitcoinExchange &operator=( const BitcoinExchange &other );
		
		static	std::vector<std::string> split(const std::string& s, char d);
		void	exchange( std::ifstream &infile, std::ifstream &data );
		void	printValue( std::string &line );

		//setters, getters
		void		pushData( const std::string &key, const std::string &value );
		std::string	&getValue( const std::string &key );
};
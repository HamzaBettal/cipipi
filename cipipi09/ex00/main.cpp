/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:34:10 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/28 18:54:28 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <istream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	BitcoinExchange btc;

	std::ifstream infile(av[1]);
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
	{
		std::cerr << "Error: could not open data.csv" << std::endl;
		infile.close();
		return 1;
	}
	try
	{
		btc.exchange(infile, dataFile);
	}
	catch ( char const *e )
	{
		std::cerr << "Error: " << e << std::endl;
	}
	infile.close();
	dataFile.close();
}
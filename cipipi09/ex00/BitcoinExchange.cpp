/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:34:05 by hbettal           #+#    #+#             */
/*   Updated: 2025/06/28 18:22:35 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other )
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other )
{
	this->data = other.data;
	return *this;
}

void BitcoinExchange::pushData( const std::string &key, const std::string &value )
{
	data.insert(std::make_pair(key, value));
}

std::string &BitcoinExchange::getValue( const std::string &key )
{
	std::map<std::string, std::string>::iterator it = data.lower_bound(key);
	std::map<std::string, std::string>::iterator fr = ++data.begin();
	if (it == fr)
		throw "Bad input => " + key;
	if (it->first != key)
		it--;
	std::cout << it->first;
	return it->second;
}

std::vector<std::string> BitcoinExchange::split( const std::string &s, char d )
{
    std::vector<std::string>	tokens;
    std::istringstream	iss(s);
    std::string	token;
    
    while (std::getline(iss, token, d))
        tokens.push_back(token);
    return tokens;
}

bool	isDigit( const std::string &str, bool f )
{
	size_t point = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[0] == '-')
			continue;
		if (str[i] == '.' && f)
		{
			if (point > 0 || i + 1 >= str.size())
				return false;
			point++;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void checkDate( std::string &line )
{
	std::vector<std::string> date = BitcoinExchange::split(line, '-');
	int mounts[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.size() != 3 || line[line.size() - 1] == '-')
		throw "Bad input => " + line;
	size_t num;
	if (!isDigit(date[0], false) || !isDigit(date[1], false) || !isDigit(date[2], false))
		throw "Bad input => " + line;
	num = std::atoi(date[0].c_str());
	if (num > 9999 || num < 1000)
		throw "Bad input => " + line;
	if ((num % 4 == 0) && ((num % 100 != 0) || (num % 400 == 0)))
		mounts[1] = 29;
	num = std::atoi(date[1].c_str());
	if ((num < 1 || num > 12) || date[1].length() != 2 || date[2].size() != 2)
		throw "Bad input => " + line;
	size_t mount = mounts[num - 1];
	num = std::atoi(date[2].c_str());
	if (num < 1 || num > mount)
		throw "Bad input => " + line;
}

void	BitcoinExchange::printValue( std::string &line )
{
	std::vector<std::string> str = BitcoinExchange::split(line, ' ');

	if (str.size() != 3 || str[1] != "|" || !isDigit(str[2], true))
	{
		std::cerr << "Error: Bad input => " + line << std::endl;
		return ;	
	}
	std::stringstream ss(str[2]);
	double num;
	if (str[2][0] == '-')
		throw std::string("not a positive number.");
	if (!(ss >> num) || num > 1000)
		throw std::string("too large a number.");
	checkDate(str[0]);
	double value = std::atof(this->getValue(str[0]).c_str());
	std::cout << " => " << str[2] << " = " << value * num << std::endl;
}

void	BitcoinExchange::exchange( std::ifstream &infile, std::ifstream &dataFile )
{
	std::string line;
	std::string key;

	std::getline(infile, line);
	if (line != "date | value")
		throw "input file should start with \"date | value\"";
	std::getline(dataFile, line);
	while (!dataFile.eof())
	{
		std::getline(dataFile, line);
		key = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		this->pushData(key, line);
	}
	while (!infile.eof())
	{
		std::getline(infile, line);
		try
		{
			if (!line.empty())
				this->printValue(line);
		}
		catch ( const std::string &e )
		{
			std::cerr << "Error: " << e << std::endl;
		}
	}
}

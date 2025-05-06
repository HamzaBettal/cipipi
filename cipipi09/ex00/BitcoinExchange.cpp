/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:34:05 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/25 16:22:28 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
	it--;
	std::cout << it->first;
	return it->second;
}

std::vector<std::string> BitcoinExchange::split(const std::string& s, char d)
{
    std::vector<std::string>	tokens;
    std::istringstream	iss(s);
    std::string	token;
    
    while (std::getline(iss, token, d))
        tokens.push_back(token);
    return tokens;
}

bool	isDigit( const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void checkDate( std::string &line )
{
	std::vector<std::string> date = BitcoinExchange::split(line, '-');
	int mounts[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (date.size() != 3)
		throw "Bad input => " + line;
	std::
	size_t num;
	if (!isDigit(date[0]) || !isDigit(date[1]) || !isDigit(date[2]))
		throw "Bad input => " + line;
	num = std::atoi(date[0].c_str());
	if (num > static_cast<size_t>(std::numeric_limits<int>::max()))
		throw "Bad input => " + line;
	num = std::atoi(date[1].c_str());
	if (num < 1 || num > 12)
		throw "Bad input => " + line;
	if (num < 10 && date[1][0] != '0')
		throw "Bad input => " + line;
	num = std::atoi(date[1].c_str());
	size_t mount = mounts[num - 1];
	num = std::atoi(date[2].c_str());
	if (num < 1 || num > mount)
		throw "Bad input => " + line;
}

void	BitcoinExchange::printValue( std::string &line )
{
	std::vector<std::string> str = BitcoinExchange::split(line, ' ');

	if (str.size() != 3)
	{
		std::cerr << "Error: Bad input => " + line << std::endl;
		return ;	
	}
	std::stringstream ss(str[2]);
	double num;
	if (!(ss >> num) || num > 1000)
	{
		if (str[2][0] == '-')
			throw "not a positive number.";
		else
			throw "too large a number.";
	}
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
			this->printValue(line);
		}
		catch ( const std::string &e )
		{
			std::cerr << "Error: " << e << std::endl;
		}
	}
}

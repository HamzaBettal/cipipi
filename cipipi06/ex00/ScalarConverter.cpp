/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:53:20 by hbettal           #+#    #+#             */
/*   Updated: 2025/02/15 12:55:13 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{}

ScalarConverter::ScalarConverter( ScalarConverter const &src )
{
    *this = src;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &rhs )
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

bool wrongInput( std::string str )
{
    for (unsigned long i = 0; i < str.length(); i++)
    {
        if (!std::isprint(str[i]))
            return true;
    }
    return false;
}

int countChar( std::string str, char ch )
{
    int count = 0;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ch)
            count++;
    }
    return count;
}

int countDigits( std::string str )
{
    int count = 0;

    if (str[0] == '-' || str[0] == '+')
        count++;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str[i]))
            count++;
    }
    return count;
}

int getType( std::string str )
{
    unsigned long point = countChar(str, '.');
    unsigned long f = countChar(str, 'f');
    unsigned long digits = countDigits(str);

    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return _CHAR;
    if (str == "nan" || str == "nanf")
        return _NAN;
    if (str == "+inf" || str == "+inff")
        return _PINF;
    if (str == "-inf" || str == "-inff")
        return _NINF;
    if (digits != str.length() - f - point || (f == 1 && str[str.length() - 1] != 'f'))
        return _INVALID;
    if (point == 0 && f == 0)
        return _INT;
    if (point == 1 && f == 1)
        return _FLOAT;
    if (point == 1 && f == 0)
        return _DOUBLE;
    return _INVALID;
}

void    printfloat( std::string str )
{
    if (str.find('.') == std::string::npos)
        std::cout << ".0";
}

void    ScalarConverter::convert( std::string str )
{
    char ch = 0;
    int n = 0;
    long inf = 0;
    float f = 0.0f;
    double d = 0.0;
    int flag = 0;

    if (wrongInput(str))
    {
        std::cerr << "Error: non printable characters detected" << std::endl;
        return;
    }

    int type = getType(str);
    inf = std::atol(str.c_str());
    
    if (type == _INVALID)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }
    if (type == _NAN)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (type == _PINF)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (type == _NINF)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    if (type == _CHAR)
    {
        ch = str[0];
        n = static_cast<int>(ch);
        f = static_cast<float>(ch);
        d = static_cast<double>(ch);
    }
    else if (type == _INT)
    {
        n = std::atoi(str.c_str());
        if (inf > std::numeric_limits<int>::max() || inf < std::numeric_limits<int>::min())
            inf > 0 ? flag = 1 : flag = -1;
        ch = static_cast<char>(n);
        f = static_cast<float>(n);
        d = static_cast<double>(n);
    }
    else if (type == _FLOAT)
    {
        f = std::atof(str.c_str());
        ch = static_cast<char>(f);
        n = static_cast<int>(f);
        d = static_cast<double>(f);
    }
    else if (type == _DOUBLE)
    {
        d = std::atof(str.c_str());
        ch = static_cast<char>(d);
        n = static_cast<int>(d);
        f = static_cast<float>(d);
    }

    if (flag)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(ch))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << ch << "'" << std::endl;

    if (flag || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << n << std::endl;

    if (flag == 1)
        std::cout << "float: impossible" << std::endl;
    else if (flag == -1)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: "  << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    if (flag == 1)
        std::cout << "double: impossible" << std::endl;
    else if (flag == -1)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

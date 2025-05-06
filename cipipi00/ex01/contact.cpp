/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:09:35 by hbettal           #+#    #+#             */
/*   Updated: 2024/09/22 21:57:47 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string Contact::getsecret()
{
    return (this->darksecret);
}

std::string Contact::getfname()
{
    return (this->firstname);
}

std::string Contact::getlname()
{
    return (this->lastname);
}

std::string Contact::getnumber()
{
    return (this->number);
}

std::string Contact::getnname()
{
    return (this->nickname);
}

void Contact::setsecret(std::string secret)
{
    this->darksecret = secret;
}

void Contact::setfname(std::string fname)
{
    this->firstname = fname;
}

void Contact::setlname(std::string lname)
{
    this->lastname = lname;
}

void Contact::setnumber(std::string number)
{
    this->number = number;
}

void Contact::setnname(std::string nname)
{
    this->nickname = nname;
}

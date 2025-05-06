/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:09:42 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/01 15:15:57 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
	this->index = 0;
	std::cout << "          Welcome :D\n\n";
}

std::string get_input(std::string msg)
{
	std::string input;

	while (input.empty())
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
	}
	return (input);
}

void    Phonebook::add_contact()
{
	std::string input;

	if (this->index > 7)
	{
		std::cout << "you reach the limit of 8 contacts, by adding the next one you gonna overwrite the first one\n";
		this->index = 0;
	}
	contacts[this->index].setfname(get_input("please enter the first name: "));
	contacts[this->index].setlname(get_input("please enter the last name: "));
	contacts[this->index].setnumber(get_input("please enter the number phone: "));
	contacts[this->index].setnname(get_input("please enter the nick name: "));
	contacts[this->index].setsecret(get_input("please enter the dark secret: "));
	std::cout << "\033[35m\t\tcontact added successfully\n\n\033[0m";
	this->index++;
}

std::string fixoutput(std::string str)
{
	int n = str.length();

	if (n > 10)
	{
		while (str.length() > 10)
			str.pop_back();
		str[str.length() - 1] = '.';
	}    
	while (n < 10)
	{
		str += ' ';
		n++;
	}
	return (str);
}

void    Phonebook::contactdisplay(std::string index)
{
	Contact *tmp = this->contacts;

	std::cout << "\033[35m\t\tContact #" << index << "\033[0m" << "\n\n";
	std::cout << "FirstName  LastName   NickName\n";
	std::cout << "----------------------------------\n|";
	std::cout << fixoutput(tmp[index[0] - '0' - 1].getfname()) + '|';
	std::cout << fixoutput(tmp[index[0] - '0' - 1].getlname()) + '|';
	std::cout << fixoutput(tmp[index[0] - '0' - 1].getnname()) + '|' << std::endl;
}

void    Phonebook::search_incontact()
{
	std::string input;

	std::cout << "which contact are u looking for (enter a number [1-8])? ";
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (input[0] >= '1' && input[0] <= '8' && !input[1])
			break ;
		else
			std::cout << "wronge input try again: ";
	}
	contactdisplay(input);
}

int main()
{
	std::string	input;
	Phonebook	phone;


	while (input.compare("EXIT"))
	{
		std::cout << "----------------------------------\n\n\n";
		std::cout << "\t\tADD : add new contact\n\t\tSEARCH : search for a specific contact\n\t\tEXIT : exit from the program\n";
		std::cout << ">> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (!input.compare("ADD"))
			phone.add_contact();
		if (!input.compare("SEARCH"))
			phone.search_incontact();
	}
}

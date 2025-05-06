/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:09:40 by hbettal           #+#    #+#             */
/*   Updated: 2025/05/05 16:50:58 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Contact
{
    public:
        std::string getfname();
        std::string getlname();
        std::string getnumber();
        std::string getnname();
        std::string getsecret();
        void setfname(std::string fname);
        void setlname(std::string lname);
        void setnumber(std::string number);
        void setnname(std::string nname);
        void setsecret(std::string secret);

    private:
        std::string firstname;
        std::string lastname;
        std::string number;
        std::string nickname;
        std::string darksecret;
};

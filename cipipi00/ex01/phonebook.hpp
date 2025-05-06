/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:09:45 by hbettal           #+#    #+#             */
/*   Updated: 2024/09/22 22:11:00 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "contact.hpp"

class Phonebook
{
    private :
        Contact contacts[8];
        int     index;

    public :
        Phonebook();
        void    add_contact();
        void    search_incontact();
        void    contactdisplay(std::string index);

};
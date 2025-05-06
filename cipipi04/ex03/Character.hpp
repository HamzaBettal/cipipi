/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:30:55 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 12:19:07 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class   Character : public ICharacter
{
	private:
		std::string _name;
		int         count;
		AMateria    **items;
		AMateria    **onfloor;

	public:
		Character( void );
		Character( std::string name );
		Character( const Character &other );
		~Character( );

		Character &operator=( const Character &other );
		
		std::string const   &getName( void ) const;
		void                equip(AMateria* m);
		void                unequip(int idx);
		void                use(int idx, ICharacter& target);
};
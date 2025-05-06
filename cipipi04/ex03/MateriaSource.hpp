/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:39:44 by hbettal           #+#    #+#             */
/*   Updated: 2024/12/11 05:05:19 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class  MateriaSource : public IMateriaSource
{
    private:
        AMateria    **materials;
    public:
        MateriaSource( void );
        MateriaSource( const MateriaSource &other );
        ~MateriaSource( );

        MateriaSource &operator=( const MateriaSource &other );

        void        learnMateria( AMateria *type );
        AMateria*   createMateria( std::string const &type );
};
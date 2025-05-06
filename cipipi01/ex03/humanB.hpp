#pragma once

#include "humanA.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
        
    public:
        HumanB();
        HumanB(std::string newName);
        ~HumanB();

        void    setWeapon(Weapon &gun);
        void    attack();
};

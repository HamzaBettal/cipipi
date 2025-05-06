#pragma once

#include "weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon      &weapon;
        
    public:
        HumanA(std::string str, Weapon &gun);
        ~HumanA();
        
        void    attack();
};

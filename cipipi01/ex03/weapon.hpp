#pragma once

#include <iostream>

class Weapon
{
    private :
        std::string type;
    public :
        Weapon(std::string name);
        const std::string &getType();
        void setType(std::string newType);
};
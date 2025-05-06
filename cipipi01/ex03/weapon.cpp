#include "weapon.hpp"

Weapon::Weapon(std::string name) : type(name)
{
}

void    Weapon::setType(std::string newType)
{
    this->type = newType;
}

const std::string &Weapon::getType()
{
    return (this->type);
}
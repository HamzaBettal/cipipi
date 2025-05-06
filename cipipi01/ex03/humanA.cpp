#include "humanA.hpp"

HumanA::HumanA(std::string str, Weapon &gun) : weapon(gun), name(str)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

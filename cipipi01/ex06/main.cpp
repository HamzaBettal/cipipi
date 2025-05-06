#include "harl.hpp"

int main(int ac, char **av)
{
    Harl    msg;

    if (ac == 2)
        msg.complain(av[1]);
    else
        std::cout << "wrong number of parameters" << std::endl;
}

#include "Finder.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
        fill_file(av);
    else
        std::cout << "Wrong Number of Parameters" << std::endl;
}

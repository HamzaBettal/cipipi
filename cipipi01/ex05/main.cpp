#include "harl.hpp"

int main()
{
    Harl msg;

    msg.complain("DEBUG");
    msg.complain("INFO");
    msg.complain("WARNING");
    msg.complain("ERROR");
    std::cout << '\n';
    msg.complain("walo~");
}

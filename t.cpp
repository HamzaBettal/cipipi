#include <sstream>
#include <iostream>


int main()
{
    std::string s = "214748364821474832147483648214748364821474836486482147483648";
    int n;
    std::stringstream ss(s.c_str());
    if (!(ss >> n))
    {
        (std::cout << "3ndk errorat\n");
        return 1;
    }
    std::cout << n << "\n";
}
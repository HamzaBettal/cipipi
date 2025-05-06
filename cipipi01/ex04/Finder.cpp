#include "Finder.hpp"
#include <string>

void    replace(std::string &fileContent, std::string s1, std::string s2)
{
    int     pos = 0;

    if (s1.empty())
        return ;
    while ((pos = fileContent.find(s1, pos)) != -1)
    {
        fileContent.erase(pos, s1.length());
        fileContent.insert(pos, s2);
        pos += s2.length();
    }
}

void    fill_file(char **av)
{
    std::ifstream   file(av[1]);
    std::string     fileContent;
    std::string     outName(av[1]);
    std::string     line;

    fileContent.c_str();
    if (!file.is_open())
    {
        std::cout << "infile is not open\n";
        return ;
    }
    while (std::getline(file, line))
    {
        if (!file.eof())
            fileContent += line + '\n';
        else
            fileContent += line;
    }
    file.close();
    outName += ".replace";
    replace(fileContent, av[2], av[3]);
    std::ofstream repFile(outName.c_str());
    if (!repFile.is_open())
    {
        std::cout << "outfile is not open\n";
        return ;
    }
    repFile << fileContent;
    repFile.close();
}


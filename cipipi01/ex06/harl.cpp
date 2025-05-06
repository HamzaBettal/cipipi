#include "harl.hpp"

int     getlevel(std::string level)
{
	std::string		lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int 	i = 0;

	while (i < 4)
	{
		if (!lvl[i].compare(level))
			break ;
		i++;
	}
	return (i);
}

void    Harl::complain(std::string level)
{
	int lvl = getlevel(level);

    switch (lvl)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "Invalid Level" << std::endl;
    }
}

void    Harl::debug()
{
	std::cout << "[ DEBUG ]\n";
    std::cout << "I've been tracking the response times of our application, and it seems like the \
database queries are taking longer than expected during peak usage.\n\n";
}

void    Harl::info()
{
	std::cout << "[ INFO ]\n";
    std::cout << "During my last review of the system logs, I found several instances of successful \
logins from new devices. This might indicate some account sharing.\n\n";
}

void    Harl::warning()
{
	std::cout << "[ WARNING ]\n";
    std::cout << "It appears that some users are experiencing intermittent connectivity issues. \
While they can still use the service, it may frustrate them if it continues.\n\n";
}

void    Harl::error()
{
	std::cout << "[ ERROR ]\n";
    std::cout << "I just received an alert that the server is down. This is a major issue, and \
we need to address it immediately to avoid downtime!\n";
}
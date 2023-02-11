#include "utils.hpp"

std::string printDate(time_t date)
{
    char buffer[80];
    struct tm * timeinfo;
    timeinfo = localtime(&date);

    std::strftime(buffer, 80, "%d/%m/%Y", timeinfo);
    std::string date_str = buffer;

    return date_str;
}

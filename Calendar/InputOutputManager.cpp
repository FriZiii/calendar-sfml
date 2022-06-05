#include "InputOutputManager.h"

bool InputOutputManager::foundFile(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;

    std::string year_string = std::to_string(year);
    std::string month_string = std::to_string(month);
    std::string day_string = std::to_string(day);

    std::string fileName = year_string + month_string + day_string + ".txt";
    file.open(fileName, std::ios::in | std::ios::out);

    if (file.is_open())
    {
        return true;
        file.close();
    }
    return false;
}

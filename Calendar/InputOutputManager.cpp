#include "InputOutputManager.h"

bool InputOutputManager::foundFile(int year, int month, int day)
{   
    this->year = year;
    this->month = month;
    this->day = day;

    std::string year_string = std::to_string(year);
    std::string month_string = std::to_string(month);
    std::string day_string = std::to_string(day);

    std::string fileName = "Events/" + year_string + month_string + day_string + ".txt";

    file.open(fileName, std::ios::in | std::ios::out);
    if (file.is_open())
    {
        return true;
    }
    return false;

    file.close();
}

void InputOutputManager::DrawTextFromFile(int year, int month, int day, sf:: Font & font, sf::RenderWindow &window, sf::Color maincolor)
{
    this->year = year;
    this->month = month;
    this->day = day;

    std::string year_string = std::to_string(year);
    std::string month_string = std::to_string(month);
    std::string day_string = std::to_string(day);

    std::string fileName = "Events/" + year_string + month_string + day_string + ".txt";

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setPosition(sf::Vector2f(922.0f, 135.0f));
    text.setFillColor(maincolor);

    std::fstream file_load;
    file_load.open(fileName,std::ios::in | std::ios::out);
    std::string line;

    if (file_load.good() == true)
    {
        while (!file_load.eof())
        {
            getline(file_load, line);
            output += line + '\n';
        }

        file_load.close();
    }

    text.setString(output);
    window.draw(text);
    output = "";

}

void InputOutputManager::SaveEventToFile(int year, int month, int day, std::string &input)
{
    this->year = year;
    this->month = month;
    this->day = day;

    std::string year_string = std::to_string(year);
    std::string month_string = std::to_string(month);
    std::string day_string = std::to_string(day);

    std::string fileName = "Events/" + year_string + month_string + day_string + ".txt";

    std::ofstream file_save;
    file_save.open(fileName);
    this->input = input;
    if (file_save.is_open())
    {
        file_save << input;
    }
    file_save.close();

}

std::string InputOutputManager::GetFileName(int year, int month, int day)
{
    std::string year_string = std::to_string(year);
    std::string month_string = std::to_string(month);
    std::string day_string = std::to_string(day);

    this->returningFileName = "Events/" + year_string + month_string + day_string + ".txt";

    return this->returningFileName;
}

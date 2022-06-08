#include "InputOutputManager.h"

bool InputOutputManager::foundFile(int year, int month, int day)
{   
    std::string fileName;
    if (day != 0 && day != 50)
    {
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month);
        std::string day_string = std::to_string(day);

        fileName = "Events/" + year_string + month_string + day_string + ".txt";
    }
    else if (day == 0)
    {
        int month_before = month - 1;
        if (month_before < 1)
        {
            month_before = 12;
            year--;
        }
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month_before);

        fileName = "Events/" + year_string + month_string + ".txt";
    }
    else if (day == 50)
    {
        int month_after = month + 1;
        if (month_after > 12)
        {
            month_after = 1;
            year++;
        }
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month_after);

        fileName = "Events/" + year_string + month_string + ".txt";
    }

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
    std::string fileName;
    if (day != 0 && day != 50)
    {
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month);
        std::string day_string = std::to_string(day);

        fileName = "Events/" + year_string + month_string + day_string + ".txt";
    }
    else if (day == 0)
    {
        int month_before = month - 1;
        if (month_before < 1)
        {
            month_before = 12;
            year--;
        }
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month_before);

        fileName = "Events/" + year_string + month_string + ".txt";
    }
    else if (day == 50)
    {
        int month_after = month + 1;
        if (month_after > 12)
        {
            month_after = 1;
            year++;
        }
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month_after);

        fileName = "Events/" + year_string + month_string + ".txt";
    }

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
    std::string fileName;
    if (day != 0 && day != 50)
    {
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month);
        std::string day_string = std::to_string(day);

        fileName = "Events/" + year_string + month_string + day_string + ".txt";
    }
    else if(day == 0)
    {
        int month_before = month - 1;
        if (month_before < 1)
        {
            month_before = 12;
            year--;
        }
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month_before);

        fileName = "Events/" + year_string + month_string + ".txt";
    }
    else if(day == 50)
    {
        int month_after = month + 1;
        if (month_after > 12)
        {
            month_after = 1;
            year++;
        }
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month_after);

        fileName = "Events/" + year_string + month_string + ".txt";
    }
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
    std::string fileName;
    if (day != 0 && day != 50)
    {
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month);
        std::string day_string = std::to_string(day);

        fileName = "Events/" + year_string + month_string + day_string + ".txt";
    }
    else if (day == 0)
    {
        int month_before = month - 1;
        if (month_before < 1)
        {
            month_before = 12;
            year--;
        }
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month_before);

        fileName = "Events/" + year_string + month_string + ".txt";
    }
    else if (day == 50)
    {
        int month_after = month + 1;
        if (month_after > 12)
        {
            month_after = 1;
            year++;
        }
        std::string year_string = std::to_string(year);
        std::string month_string = std::to_string(month_after);

        fileName = "Events/" + year_string + month_string + ".txt";
    }

    return fileName;
}

#include <SFML/Graphics.hpp>

#include "SidePanel.h"
#include "Background.h"
#include "DaysOfTheWeek.h"
#include "DaysBoxes.h"
#include "Button.h"
#include "Logo.h"
#include "MonthAndYear.h"
#include "Functions.h"
#include "RightBarText.h"

#include <vector>
#include <time.h>

#pragma warning(disable : 4996)

int main()
{
    //Antialiasing
    sf::ContextSettings contextsettings;
    contextsettings.antialiasingLevel = 8;

    //Window
    sf::RenderWindow window(sf::VideoMode(1200, 610), "Calendar", 4U, contextsettings);

    //Startup value
    bool home = true;
    bool credits = false;
    bool settings = false;

    bool isClicked = false;

    //Font
    sf::Font font; font.loadFromFile("Fonts/WILD_WORLD.otf");

    //Background
    Background background;

    //Left and Right bar
    SidePanel left(sf::Vector2f(266.0f, 610.0f), sf::Vector2f(0.0f, 0.0f));
    SidePanel right(sf::Vector2f(286.0f, 87.0f), sf::Vector2f(914.0f, 0.0f));

    //Logo
    Logo logo;

    //Buttons left bar
    std::vector<Button>button;
    button.push_back(Button(sf::Vector2f(20.0f, 190.0f), font, "HOME"));
    button.push_back(Button(sf::Vector2f(20.0f, 290.0f), font, "SETTINGS"));
    button.push_back(Button(sf::Vector2f(20.0f, 390.0f), font, "CREDITS"));
    button.push_back(Button(sf::Vector2f(20.0f, 490.0f), font, "EXIT"));

    //Month and Year
        //Getting actual month and year
        time_t theTime = time(NULL);
        struct tm* aTime = localtime(&theTime);
        int month = aTime->tm_mon + 1;
        int year = aTime->tm_year + 1900;

    MonthAndYear monthAndYear(month, year, font);

    //Days of the week
    std::vector<DaysOfTheWeek>daysoftheweek;

    for (int i = 0; i <= 6; i++)
    {
        sf::Vector2f position(293.0f + (float)i * (68.0f + 20.0f), 121.0f);
        daysoftheweek.push_back(DaysOfTheWeek(i, position, font));
    }

    //Boxes of the day
    std::vector<DaysBoxes>daysboxes;

    int daysCount = 0;
    int weekDay = zellerArgorithm(monthAndYear.GetMonth(), monthAndYear.GetYear()); //How many days we have to skip
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            if (daysCount < DaysCount(monthAndYear.GetMonth(), monthAndYear.GetYear()))//If the current day is less than the number of days in the month, we increase the next day
            {
                daysCount++;
            }
            else
            {
                daysCount = 50;//otherwise, we set a placeholder
            }

            sf::Vector2f position(293.0f + (float)j * (68.0f + 20.0f), 151.0f + (float)i * 72.0f);
            daysboxes.push_back(DaysBoxes(position, font, daysCount, weekDay));
            weekDay--;
        }
    }

    //Right bar text;
    int day{};
    RightBarText rightbartext(font);

    //Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                isClicked = true;
            }
        }

        //Updates
        for (Button& button : button)
            button.Update(window);

        if (button[0].IsClicked(window))
        {
            home = true;
            settings = false;
            credits = false;
        }
        else if (button[1].IsClicked(window))
        {
            home = false;
            settings = true;
            credits = false;
        }
        else if (button[2].IsClicked(window))
        {
            home = false;
            settings = false;
            credits = true;
        }
        else if (button[3].IsClicked(window))
            window.close();

        if (home && !credits && !settings)
        {
            if (isClicked)
            {
                monthAndYear.Update(window);
                isClicked = false;
            }
            monthAndYear.HoverEffect(window);


            int daysCount = 0;
            int weekDay = zellerArgorithm(monthAndYear.GetMonth(), monthAndYear.GetYear());//How many days we have to skip
            for (DaysBoxes& daysboxes : daysboxes)
            {
                if (weekDay <= 0)
                {
                    if (daysCount < DaysCount(monthAndYear.GetMonth(), monthAndYear.GetYear()))//If the current day is less than the number of days in the month, we increase the next day
                        daysCount++;
                    else
                        daysCount = 50;//otherwise, we set a placeholder
                }
                daysboxes.Update(window, daysCount, weekDay);
                weekDay--;

                if (daysboxes.isClick(window))
                    day = daysboxes.GetDay(window);
            }

            rightbartext.Update(day, monthAndYear.GetMonthString(), right.GetSize(), right.GetPosition());
        }

        //Draw
        window.clear(sf::Color::White);
        left.Draw(window);
        logo.Draw(window);

        for (Button& button : button)
            button.Draw(window);

        if (home && !credits && !settings)
        {
            background.Draw(window);

            right.Draw(window);

            for (DaysOfTheWeek& daysoftheweek : daysoftheweek)
                daysoftheweek.Draw(window);

            for (DaysBoxes& daysboxes : daysboxes)
                daysboxes.Draw(window);

            monthAndYear.Draw(window);

            rightbartext.Draw(window);
        }
        window.display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>

#include "LeftBar.h"
#include "Background.h"
#include "DaysOfTheWeek.h"
#include "DaysBoxes.h"
#include "Button.h"
#include "Logo.h"
#include "MonthAndYear.h"

#include <vector>

int main()
{
    //Window
    sf::RenderWindow window(sf::VideoMode(1200, 610), "Calendar");

    //Left bar
    LeftBar left;

    //Background
    Background background;

    //Font
    sf::Font font; font.loadFromFile("Fonts/WILD_WORLD.otf");

    //Month and Year
    MonthAndYear monthAndYear(5, 2022, font);

    //Days of the week
    std::vector<DaysOfTheWeek>daysoftheweek;
    for (int i = 0; i <= 6; i++)
    {
        sf::Vector2f position(293 + i * (68 + 20), 121);
        daysoftheweek.push_back(DaysOfTheWeek(i, position, font));
    }

    //Boxes of the day
    std::vector<DaysBoxes>daysboxes;
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            sf::Vector2f position(293 + j * (68 + 20), 151+i*72);
            daysboxes.push_back(DaysBoxes(position));
        }
    }

    //Buttons left bar
    std::vector<Button>button;
    button.push_back(Button(sf::Vector2f(20, 190), font, "HOME"));
    button.push_back(Button(sf::Vector2f(20, 290), font, "SETTINGS"));
    button.push_back(Button(sf::Vector2f(20, 390), font, "CREDITS"));
    button.push_back(Button(sf::Vector2f(20, 490), font, "EXIT"));

    //Logo
    Logo logo;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        //Updates
        for (Button& button : button)
            button.Update(window);

        monthAndYear.Update(window);

        for (DaysBoxes& daysboxes : daysboxes)
        {
            daysboxes.Update(window);
        }

        //Draw
        window.clear();

        background.Draw(window);

        for (DaysOfTheWeek& daysoftheweek : daysoftheweek)
            daysoftheweek.Draw(window);

        for (DaysBoxes& daysboxes : daysboxes)
            daysboxes.Draw(window);

        monthAndYear.Draw(window);

        left.Draw(window);

        logo.Draw(window);

        for (Button& button : button)
            button.Draw(window);

        window.display();
    }

    return 0;
}
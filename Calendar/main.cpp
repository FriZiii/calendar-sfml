#include <SFML/Graphics.hpp>
#include "LeftBar.h"
#include "Background.h"
#include "DaysOfTheWeek.h"
#include "DaysBoxes.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 610), "Calendar");
    LeftBar left;
    Background background;

    std::vector<DaysOfTheWeek>daysoftheweek;
    for (int i = 0; i <= 6; i++)
    {
        sf::Vector2f position(297+i*(68+20), 121);
        daysoftheweek.push_back(DaysOfTheWeek(i, position));
    }

    std::vector<DaysBoxes>daysboxes;
    for (int j = 0; j <= 5; j++)
    {
        for (int i = 0; i <= 6; i++)
        {
            sf::Vector2f position(293 + i * (68 + 20), 151+j*72);
            daysboxes.push_back(DaysBoxes(position));
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        background.Draw(window);
        for (DaysOfTheWeek& daysoftheweek : daysoftheweek)
            daysoftheweek.Draw(window);

        for (DaysBoxes& daysboxes : daysboxes)
            daysboxes.Draw(window);

        left.Draw(window);
        window.display();
    }

    return 0;
}
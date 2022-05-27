#pragma once
#include <SFML/Graphics.hpp>
class Background
{
    sf::RectangleShape horizontalline;
    sf::RectangleShape verticalline;
public:
    Background();
    void Draw(sf::RenderWindow& window);
};

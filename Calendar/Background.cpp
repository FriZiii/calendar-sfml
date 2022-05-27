#include "Background.h"

Background::Background()
{
    horizontalline.setSize(sf::Vector2f(934.f, 2.f));
    horizontalline.setPosition(sf::Vector2f(266.f, 87.f));
    sf::Color Grey(220, 220, 220);
    horizontalline.setFillColor(Grey);

    verticalline.setSize(sf::Vector2f(2.f, 610.f));
    verticalline.setPosition(sf::Vector2f(912.f, 0.f));
    verticalline.setFillColor(Grey);
}

void Background::Draw(sf::RenderWindow& window)
{
    window.draw(horizontalline);
    window.draw(verticalline);
}

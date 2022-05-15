#pragma once
#include <SFML/Graphics.hpp>
class DaysBoxes
{
	sf::RectangleShape body;
	sf::Vector2f position;
	sf::Color grey;
public:
	DaysBoxes(sf::Vector2f position);
	void Draw(sf::RenderWindow& window) { window.draw(body); }
};


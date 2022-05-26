#pragma once
#include <SFML/Graphics.hpp>

class SidePanel
{
	sf::RectangleShape body;
	sf::Vector2f size;
	sf::Vector2f position;
public:
	SidePanel(sf::Vector2f size, sf::Vector2f position);
	void Draw(sf::RenderWindow& window) { window.draw(body); }
	sf::Vector2f GetSize();
	sf::Vector2f GetPosition();
};


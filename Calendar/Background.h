#pragma once
#include <SFML/Graphics.hpp>
class Background
{
	sf::RectangleShape body;
	sf::Texture texture;
public:
	Background();
	void Draw(sf::RenderWindow& window) { window.draw(body); }
};


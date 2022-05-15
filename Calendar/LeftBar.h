#pragma once
#include <SFML/Graphics.hpp>

class LeftBar
{
	sf::RectangleShape body;

public:
	LeftBar();
	void Draw(sf::RenderWindow& window) { window.draw(body); }
};


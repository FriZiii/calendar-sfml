#pragma once
#include <SFML/Graphics.hpp>
class Logo
{
	sf::RectangleShape body;
	sf::Vector2f position;
	sf::Texture texture;
public:
	Logo();
	void Draw(sf::RenderWindow& window) { window.draw(body); }
};


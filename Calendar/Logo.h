#pragma once
#include <SFML/Graphics.hpp>
class Logo
{
	sf::RectangleShape body;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Texture texture;
	std::string file;
public:
	Logo(sf::Vector2f position, sf::Vector2f size, std::string file);
	void Draw(sf::RenderWindow& window) { window.draw(body); }
};


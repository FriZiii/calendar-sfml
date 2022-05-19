#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class DaysBoxes
{
	sf::RectangleShape body;
	sf::Vector2f position;
	sf::Color grey;
	sf::Color purple;
public:
	DaysBoxes(sf::Vector2f position);
	void Draw(sf::RenderWindow& window) { window.draw(body); }
	void Update(sf::RenderWindow& window);
};


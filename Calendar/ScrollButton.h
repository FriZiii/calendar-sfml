#pragma once
#include <SFML/Graphics.hpp>
class ScrollButton
{
	sf::RectangleShape body;
	sf::RectangleShape button;

	sf::Vector2f position;
	sf::Vector2f size;

	sf::Vector2f buttonposition;
	sf::Vector2f buttonsize;

public:
	ScrollButton(sf::Vector2f position);
	void Update(sf::RenderWindow& window, std::string RGB);
	void Draw(sf::RenderWindow& window) { window.draw(body); window.draw(button); }
	int GetIterator() { return (int)((button.getPosition().x - position.x) / 2); }
};


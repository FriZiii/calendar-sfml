#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
	sf::ConvexShape body;
	sf::Vector2f position;

	sf::Text text;
	sf::Font font;
	sf::Vector2f textpossition;
	std::string textString;
	bool small;


public:
	Button(sf::Vector2f position, sf::Font& font, std::string textString, bool small, sf::Color maincolor);
	void Draw(sf::RenderWindow& window) { window.draw(body); window.draw(text); }
	void Update(sf::RenderWindow& window, sf::Color maincolor);
	bool IsHover(sf::RenderWindow& window);
};


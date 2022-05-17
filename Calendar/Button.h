#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
	sf::ConvexShape body;
	sf::Vector2f position;

	sf::Text text;
	sf::Color black;
	sf::Font font;
	sf::Vector2f textpossition;
	std::string textString;


public:
	Button(sf::Vector2f position, sf::Font& font, std::string textString);
	void Draw(sf::RenderWindow& window) { window.draw(body); window.draw(text); }
	void Update(sf::RenderWindow& window);
	bool IsClicked(sf::RenderWindow& window);
};


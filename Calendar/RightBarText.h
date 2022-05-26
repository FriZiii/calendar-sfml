#pragma once
#include <SFML/Graphics.hpp>

class RightBarText
{
	sf::Text text;
	sf::Font font;
	sf::Vector2f textPossition;

	std::string dayString;
	std::string monthString;

	std::string textString;
public:
	RightBarText(sf::Font& font);
	void Update(int day, std::string monthString, sf::Vector2f size, sf::Vector2f position);
	void Draw(sf::RenderWindow& window);
};


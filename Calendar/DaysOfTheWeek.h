#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class DaysOfTheWeek
{
	sf::Text text;
	sf::Color black;
	sf::Font font;
	sf::Vector2f possition;
	std::string textString;
public:
	DaysOfTheWeek(int i, sf::Vector2f position);
	void Draw(sf::RenderWindow& window);
};


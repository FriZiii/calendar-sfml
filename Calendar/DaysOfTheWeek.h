#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class DaysOfTheWeek
{
	sf::RectangleShape box;
	sf::Vector2f possition;
	sf::Text text;
	sf::Color black;
	sf::Font font;
	std::string textString[7] = {"MON", "TUE", "WED", "THU" ,"FRI" ,"SAT", "SUN"};
public:
	DaysOfTheWeek(int i, sf::Vector2f position, sf::Font &font);
	void Draw(sf::RenderWindow& window);
};


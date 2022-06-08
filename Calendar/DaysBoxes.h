#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class DaysBoxes
{
	sf::RectangleShape body;
	sf::Vector2f position;
	sf::Color grey;
	bool isClicked;

	int day{};
	sf::Text text;
	sf::Font font;
	std::string textString;
public:
	DaysBoxes(sf::Vector2f position, sf::Font& font, int day, int weekDay);
	void Draw(sf::RenderWindow& window) { window.draw(body); window.draw(text); }
	void Update(sf::RenderWindow& window, int day, int weekDay, sf::Color maincolor, int R, int G, int B, int actuallDay, int actuallMonth, int chosenMonth, int actuallYear, int chosenYear);
	bool isClick(sf::RenderWindow& window);
	unsigned int GetDay(sf::RenderWindow& window);
	bool IsBoxCheck() { return isClicked; }
};


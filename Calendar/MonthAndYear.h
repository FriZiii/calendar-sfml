#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class MonthAndYear
{
	sf::Text textMonth;
	sf::Text textYear;
	sf::Color black;
	sf::Font font;

	sf::Vector2f textPossitionMonth;
	sf::Vector2f textPossitionYear;
	std::string textStringMonth[13] = {" ","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
	std::string textStringYear;

	int year = 2022;
	int month = 5;

	//Button
	sf::RectangleShape buttonLeft;
	sf::RectangleShape buttonRight;

	sf::Vector2f leftPosition;
	sf::Vector2f rightPosition;

	sf::Texture texture;
	sf::Texture textureHover;

	bool isClicked;

public:
	MonthAndYear(int month, int year, sf::Font &font);
	void Draw(sf::RenderWindow& window) { window.draw(textMonth); window.draw(textYear); window.draw(buttonLeft); window.draw(buttonRight);}
	void Update(sf::RenderWindow& window);
	void HoverEffect(sf::RenderWindow& window);
	unsigned int GetMonth() { return month; }
	unsigned int GetYear(){ return year; }
	std::string GetMonthString();
};


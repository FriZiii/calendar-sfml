#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class MonthAndYear
{
	sf::Text textMonth;
	sf::Text textYear;
	sf::Color black;
	sf::Font font;

	sf::Vector2f textPossitionMonth;
	sf::Vector2f textPossitionYear;
	std::string textStringMonth[12] = {"January ","February ","March ","April ","May ","June ","July ","August ","September ","October ","November ","December " };
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

public:
	MonthAndYear(int month, int year, sf::Font &font);
	void Draw(sf::RenderWindow& window) { window.draw(textMonth); window.draw(textYear); window.draw(buttonLeft); }
	unsigned int GetMonth() { return month; }
	unsigned int GetYear(){ return year; }
};


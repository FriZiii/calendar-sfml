#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class TextInputDrawing
{
	sf::Text text;
	sf::Font font;

	std::string textString;

	int marks;
	sf::Time elapsed;

public:
	bool show_cursor;
	TextInputDrawing(sf::Font font, std::string textString);
	void Update(std::string textString, sf::Clock &cursorClock, int total_marks);
	void Draw(sf::RenderWindow& window) { window.draw(text); };
};


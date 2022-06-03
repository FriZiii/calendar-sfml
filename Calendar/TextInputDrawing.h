#pragma once
#include <SFML/Graphics.hpp>
class TextInputDrawing
{
	sf::Text text;
	sf::Font font;

	std::string textString;

	int marks;
	static bool show_cursor;
public:
	TextInputDrawing(sf::Font font, std::string textString);
	void Update(std::string textString);
	void Draw(sf::RenderWindow& window) { window.draw(text); };
};


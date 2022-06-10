#include "TextInputDrawing.h"

TextInputDrawing::TextInputDrawing(sf::Font font, std::string textString)
{
	this->font = font;
	this->textString = textString;
	text.setFillColor(sf::Color::Black);
	text.setString(textString);
	text.setCharacterSize(24);
}

void TextInputDrawing::Update(std::string textString, sf::Clock& cursorClock)
{
	sf::Time elapsed = cursorClock.getElapsedTime();
	if (elapsed >= sf::seconds(0.7f))
	{
		show_cursor = !show_cursor;
		cursorClock.restart();
	}

	this->textString = textString;
	text.setFont(font);
	text.setString(textString + (show_cursor ? '|' : ' '));
	text.setPosition(sf::Vector2f(922.0f, 135.0f));
}

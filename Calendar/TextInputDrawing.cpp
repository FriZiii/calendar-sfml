#include "TextInputDrawing.h"

TextInputDrawing::TextInputDrawing(sf::Font font, std::string textString)
{
	this->font = font;
	this->textString = textString;
	text.setFillColor(sf::Color::Black);
	text.setString(textString);
	text.setCharacterSize(24);
}

void TextInputDrawing::Update(std::string textString, sf::Clock& cursorClock, int total_marks)
{
	sf::Time elapsed = cursorClock.getElapsedTime();
	if (elapsed >= sf::seconds(0.53f))
	{
		show_cursor = !show_cursor;
		cursorClock.restart();
	}

	this->textString = textString;
	text.setFont(font);
	if(total_marks <=208)
		text.setString(textString + (show_cursor ? '|' : ' '));
	else
		text.setString(textString);

	text.setPosition(sf::Vector2f(922.0f, 135.0f));
}

#include "TextInputDrawing.h"

TextInputDrawing::TextInputDrawing(sf::Font font, std::string textString)
{
	this->font = font;
	this->textString = textString;
	text.setFillColor(sf::Color::Black);
	text.setString(textString);
	text.setCharacterSize(24);
}

void TextInputDrawing::Update(std::string textString)
{
	this->textString = textString;
	text.setFont(font);
	text.setString(textString);
	text.setPosition(sf::Vector2f(922.0f, 135.0f));
}

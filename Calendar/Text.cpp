#include "Text.h"

Text::Text(std::string textString, sf::Vector2f position, sf::Font &font, int fontSize)
{
	this->font = font;
	this->position = position;
	this->textString = textString;

	text.setFont(font);
	text.setString(textString);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(fontSize);
	text.setPosition(position);
}

Text::Text(std::string textString, sf::Vector2f position, sf::Font &font, std::string coloredtextString, sf::Color maincolor, int fontSize)
{
	this->font = font;
	this->position = position;
	this->textString = textString;

	text.setFont(font);
	text.setString(textString);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(fontSize);
	text.setPosition(position);

	this->coloredtextString = coloredtextString;

	coloredText.setFont(font);
	coloredText.setString(coloredtextString);
	coloredText.setFillColor(maincolor);
	coloredText.setCharacterSize(fontSize);
	coloredText.setPosition(text.getGlobalBounds().left + text.getGlobalBounds().width, position.y);
}

void Text::Update(sf::Color maincolor)
{
	coloredText.setFillColor(maincolor);
}

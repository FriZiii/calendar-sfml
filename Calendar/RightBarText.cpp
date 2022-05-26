#include "RightBarText.h"

RightBarText::RightBarText(sf::Font& font)
{
	this->font = font;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(textString);
	text.setCharacterSize(32);
}

void RightBarText::Update(std::string dayString, std::string monthString, sf::Vector2f size, sf::Vector2f position)
{
	textString = dayString + " " + monthString;
	text.setString(textString);
	text.setPosition(sf::Vector2f(position.x + (size.x/2.0f) - (text.getGlobalBounds().width/2.0f), position.y + (size.y / 2.0f) - (text.getGlobalBounds().height/2.0f) - 5.0f));
}

void RightBarText::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}

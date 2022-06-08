#include "Text.h"

Text::Text(std::string textString, sf::Vector2f position, sf::Font &font, int fontSize)
{
	text.setFont(font);
	text.setString(textString);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(fontSize);
	text.setPosition(position);
}

Text::Text(std::string textString, sf::Vector2f position, sf::Font &font, std::string coloredtextString, sf::Color maincolor, int fontSize)
{
	text.setFont(font);
	text.setString(textString);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(fontSize);
	text.setPosition(position);

	coloredText.setFont(font);
	coloredText.setString(coloredtextString);
	coloredText.setFillColor(maincolor);
	coloredText.setCharacterSize(fontSize);
	coloredText.setPosition(text.getGlobalBounds().left + text.getGlobalBounds().width, position.y);
}

Text::Text(std::string coloredtextString, std::string textString, sf::Vector2f position, sf::Font& font, sf::Color maincolor, int fontSize)
{
	coloredText.setFont(font);
	coloredText.setString(coloredtextString);
	coloredText.setFillColor(maincolor);
	coloredText.setCharacterSize(fontSize);
	coloredText.setPosition(position);

	text.setFont(font);
	text.setString(textString);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(fontSize);
	text.setPosition(coloredText.getGlobalBounds().left + coloredText.getGlobalBounds().width, position.y);

}

Text::Text(std::string textString1, std::string coloredtextString, std::string textString2, sf::Vector2f position, sf::Font& font, sf::Color maincolor, int fontSize)
{
	text.setFont(font);
	text.setString(textString1);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(fontSize);
	text.setPosition(position);

	coloredText.setFont(font);
	coloredText.setString(coloredtextString);
	coloredText.setFillColor(maincolor);
	coloredText.setCharacterSize(fontSize);
	coloredText.setPosition(text.getGlobalBounds().left + text.getGlobalBounds().width, position.y);

	text2.setFont(font);
	text2.setString(textString2);
	text2.setFillColor(sf::Color::Black);
	text2.setCharacterSize(fontSize);
	text2.setPosition(coloredText.getGlobalBounds().left + coloredText.getGlobalBounds().width, position.y);
}

void Text::Update(sf::Color maincolor)
{
	coloredText.setFillColor(maincolor);
}

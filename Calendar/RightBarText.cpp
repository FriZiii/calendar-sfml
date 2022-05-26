#include "RightBarText.h"

RightBarText::RightBarText(sf::Font& font)
{
	this->font = font;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(textString);
	text.setCharacterSize(30);
}

void RightBarText::Update(int day, std::string monthString, sf::Vector2f size, sf::Vector2f position)
{
	if (day % 10 == 1 || day % 20 == 1 || day % 30 == 1)
	{
		dayString = std::to_string(day);
		std::transform(monthString.begin(), monthString.end(), monthString.begin(), ::tolower),
		textString = dayString + "st of " + monthString;
	}
	else if (day % 10 == 2 || day % 20 == 2 || day % 30 == 2)
	{
		dayString = std::to_string(day);
		std::transform(monthString.begin(), monthString.end(), monthString.begin(), ::tolower),
		textString = dayString + "nd of " + monthString;
	}
	else if (day % 10 == 3 || day % 20 == 3 || day % 30 == 3)
	{
		dayString = std::to_string(day);
		std::transform(monthString.begin(), monthString.end(), monthString.begin(), ::tolower),
		textString = dayString + "rd of " + monthString;
	}
	else if (day == 0 || day >=50)
	{
		dayString = "";
		textString = monthString;
	}
	else
	{
		dayString = std::to_string(day);
		std::transform(monthString.begin(), monthString.end(), monthString.begin(), ::tolower),
		textString = dayString + "th of " + monthString;
	}

	text.setString(textString);
	text.setPosition(sf::Vector2f(position.x + (size.x/2.0f) - (text.getGlobalBounds().width/2.0f), position.y + (size.y / 2.0f) - (text.getGlobalBounds().height/2.0f) - 5.0f));
}

void RightBarText::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}

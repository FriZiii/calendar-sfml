#include "Button.h"

Button::Button(sf::Vector2f position, sf::Font &font, std::string textString)
{
	//Button
	body.setPointCount(4);
	body.setPoint(0, sf::Vector2f(39, 3));
	body.setPoint(1, sf::Vector2f(6, 59));
	body.setPoint(2, sf::Vector2f(189, 59));
	body.setPoint(3, sf::Vector2f(222, 3));

	this->position = position;
	body.setPosition(position);
	body.setFillColor(sf::Color::White);

	//Text
	this->font = font;
	this->textString = textString;

	text.setFont(font);
	text.setCharacterSize(22);
	text.setFillColor(black);
	text.setString(textString);

	text.setPosition((position.x + 39.0f) + 75.0f - (text.getGlobalBounds().width/2.0f), position.y + 28.0f - (text.getGlobalBounds().height / 2.0f));

}

void Button::Update(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		//Button
		body.setPoint(0, sf::Vector2f(35, 0));
		body.setPoint(1, sf::Vector2f(0, 63));
		body.setPoint(2, sf::Vector2f(194, 63));
		body.setPoint(3, sf::Vector2f(228, 0));

		body.setPosition(position.x - 2.0f, position.y + 1.0f);

		//Text
		sf::Color Purple(93, 9, 172);
		text.setFillColor(Purple);
	}
	else
	{
		//Button
		body.setPoint(0, sf::Vector2f(39, 3));
		body.setPoint(1, sf::Vector2f(6, 59));
		body.setPoint(2, sf::Vector2f(189, 59));
		body.setPoint(3, sf::Vector2f(222, 3));

		body.setPosition(position);

		//Text
		text.setFillColor(sf::Color::Black);
	}
}

bool Button::IsClicked(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

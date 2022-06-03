#include "Button.h"

Button::Button(sf::Vector2f position, sf::Font &font, std::string textString, bool small, sf::Color maincolor)
{
	this->small = small;
	//Button
	if (!small)
	{
		body.setPointCount(4);
		body.setPoint(0, sf::Vector2f(39, 3));
		body.setPoint(1, sf::Vector2f(6, 59));
		body.setPoint(2, sf::Vector2f(189, 59));
		body.setPoint(3, sf::Vector2f(222, 3));
		body.setFillColor(sf::Color::White);

		this->font = font;
		this->textString = textString;

		text.setFont(font);
		text.setCharacterSize(20);
		text.setString(textString);

		text.setPosition((position.x + 39.0f) + 75.0f - (text.getGlobalBounds().width / 2.0f), position.y + 28.0f - (text.getGlobalBounds().height / 2.0f));
	}
	if (small)
	{
		body.setPointCount(4);
		body.setPoint(0, sf::Vector2f(39 + 4, 3 + 3));
		body.setPoint(1, sf::Vector2f(6 + 6, 59 - 4));
		body.setPoint(2, sf::Vector2f(189 - 4, 59 - 4));
		body.setPoint(3, sf::Vector2f(222 - 6, 3 + 3));
		body.setFillColor(maincolor);

		this->font = font;
		this->textString = textString;

		text.setFont(font);
		text.setCharacterSize(18);
		text.setFillColor(sf::Color::White);
		text.setString(textString);

		text.setPosition((position.x + 39.0f) + 75.0f - (text.getGlobalBounds().width / 2.0f), position.y + 28.0f - (text.getGlobalBounds().height / 2.0f));
	}


	this->position = position;
	body.setPosition(position);
}

void Button::Update(sf::RenderWindow& window, sf::Color maincolor)
{
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		//Button
		if (!small)
		{
			body.setPoint(0, sf::Vector2f(35, 0));
			body.setPoint(1, sf::Vector2f(0, 63));
			body.setPoint(2, sf::Vector2f(194, 63));
			body.setPoint(3, sf::Vector2f(228, 0));

			text.setFillColor(sf::Color::Black);

			body.setPosition(position.x - 2.0f, position.y + 1.0f);

			//Text
			text.setFillColor(maincolor);
		}
		if (small)
		{
			body.setPoint(0, sf::Vector2f(39 + 2, 3 + 1.5));
			body.setPoint(1, sf::Vector2f(6 + 3, 59 - 2));
			body.setPoint(2, sf::Vector2f(189 - 2, 59 - 2));
			body.setPoint(3, sf::Vector2f(222 - 3, 3 + 1.5));
			body.setFillColor(maincolor);

			//Text
			text.setFillColor(sf::Color::White);
		}
	}
	else
	{
		//Button
		if (!small)
		{	
			body.setPoint(0, sf::Vector2f(39, 3));
			body.setPoint(1, sf::Vector2f(6, 59));
			body.setPoint(2, sf::Vector2f(190, 59));
			body.setPoint(3, sf::Vector2f(222, 3));
			text.setFillColor(sf::Color::Black);
		}

		if (small)
		{
			body.setPointCount(4);
			body.setPoint(0, sf::Vector2f(39 + 4, 3 + 3));
			body.setPoint(1, sf::Vector2f(6 + 6, 59 - 4));
			body.setPoint(2, sf::Vector2f(189 - 6, 59 - 4));
			body.setPoint(3, sf::Vector2f(222 - 6, 3 + 3));
			body.setFillColor(maincolor);

			text.setFillColor(sf::Color::White);
		}

		body.setPosition(position);

	}
}

bool Button::IsHover(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		return true;
	}
	else
	{
		return false;
	}
}

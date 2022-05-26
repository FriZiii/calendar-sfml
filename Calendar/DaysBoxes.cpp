#include "DaysBoxes.h"

DaysBoxes::DaysBoxes(sf::Vector2f position, sf::Font &font, int day, int weekDay)
{
	this->grey = sf::Color(232, 232, 232);
	this->purple = sf::Color(93, 9, 172);
	this->lightPurple = sf::Color(123, 29, 211);

	this->position = position;
	this->isClicked = false;

	body.setSize(sf::Vector2f(67.63f, 58.18f));
	body.setFillColor(grey);
	body.setPosition(position);

	//Days
	text.setFont(font);
	text.setCharacterSize(28);
	text.setFillColor(sf::Color::Black);
	if (weekDay > 0)
	{
		text.setString(" ");
	}
	else if(weekDay <= 0)
	{
		if (day >= 50)
			text.setString(" ");
		else
			text.setString(std::to_string(day));
	}

	text.setPosition(body.getPosition().x + (body.getSize().x / 2.0f) - (text.getGlobalBounds().width / 2.0f), body.getPosition().y + (body.getSize().y / 2.0f) - (text.getGlobalBounds().height / 2.0f));
}

void DaysBoxes::Update(sf::RenderWindow& window, int day, int weekDay)
{
	this->day = day;
	//Hover and click effect
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		this->body.setFillColor(lightPurple);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isClicked = true;
			this->body.setFillColor(purple);
		}

		if (isClicked)
		{
			this->text.setFillColor(sf::Color::White);
			this->body.setFillColor(purple);
		}
	}
	else
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isClicked = false;
		}

		if (!isClicked)
		{
			this->body.setFillColor(grey);
			this->text.setFillColor(sf::Color::Black);
		}
	}

	//Days 
	if (weekDay > 0)
	{
		text.setString(" ");
	}
	else
	{
		if (day >= 50)
			text.setString(" ");
		else
			text.setString(std::to_string(day));
	}
	text.setPosition(body.getPosition().x + (body.getSize().x / 2.0f) - (text.getGlobalBounds().width / 2.0f), body.getPosition().y + (body.getSize().y / 2.0f) - (text.getGlobalBounds().height / 2.0f));
}

bool DaysBoxes::isClick(sf::RenderWindow& window)
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

unsigned int DaysBoxes::GetDay(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return day;
		}
	}
}


#include "DaysBoxes.h"

DaysBoxes::DaysBoxes(sf::Vector2f position)
{
	this->grey = sf::Color(232, 232, 232);
	this->purple = sf::Color(93, 9, 172);
	this->position = position;
	this->isClicked = false;

	body.setSize(sf::Vector2f(67.63f, 58.18f));
	body.setFillColor(grey);
	body.setPosition(position);
}

void DaysBoxes::Update(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		this->body.setFillColor(sf::Color::Black);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isClicked = true;
			this->body.setFillColor(purple);
		}

		if (isClicked)
		{
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
		}
	}
}

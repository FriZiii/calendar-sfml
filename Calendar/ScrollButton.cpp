#include "ScrollButton.h"

ScrollButton::ScrollButton(sf::Vector2f position)
{
	this->position = position;

	this->size = sf::Vector2f(16 + 255 * 2, 20);
	this->buttonsize = sf::Vector2f(15, 20);

	this->buttonposition = sf::Vector2f(position.x, position.y);



	body.setSize(size);
	button.setSize(buttonsize);

	body.setPosition(position);
	button.setPosition(position);

	body.setFillColor(sf::Color(217, 217, 217));
	button.setFillColor(sf::Color(0, 0, 0));
}

void ScrollButton::Update(sf::RenderWindow& window, std::string RGB)
{
	float mousefloatX = (float)(sf::Mouse::getPosition(window).x);
	float mousefloatY = (float)(sf::Mouse::getPosition(window).y);
	if (mousefloatX > body.getGlobalBounds().left && mousefloatX < body.getGlobalBounds().left + body.getGlobalBounds().width - button.getSize().x)
	{
		if (mousefloatY > body.getGlobalBounds().top && mousefloatY < body.getGlobalBounds().top + body.getGlobalBounds().height)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				button.setPosition(mousefloatX, position.y);
		}
	}

	if (RGB == "R")
	{
		button.setFillColor(sf::Color(((int)(button.getPosition().x - position.x) / 2), 0, 0));
	}
	else if (RGB == "G")
	{
		button.setFillColor(sf::Color(0, ((int)(button.getPosition().x - position.x) / 2), 0));
	}
	else if (RGB == "B")
	{
		button.setFillColor(sf::Color(0, 0, ((int)((button.getPosition().x - position.x) / 2))));
	}
}

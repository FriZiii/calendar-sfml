#include "DaysBoxes.h"

DaysBoxes::DaysBoxes(sf::Vector2f position)
{
	body.setSize(sf::Vector2f(67.63f, 58.18f));
	this->grey = sf::Color(232, 232, 232);
	this->purple = sf::Color(93, 9, 172);
	this->position = position;
	body.setFillColor(grey);
	body.setPosition(position);
}

void DaysBoxes::Update(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		body.setFillColor(purple);
	}
	else 
	{
		body.setFillColor(grey);
	}
}

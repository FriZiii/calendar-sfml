#include "CreateYourOwnColorButton.h"

CreateYourOwnColorButton::CreateYourOwnColorButton(sf::Vector2f position)
{
	this->position = position;
	this->size = sf::Vector2f(120.0f, 120.0f);

	body.setSize(size);
	body.setOrigin(sf::Vector2f(size.x /2, size.y /2));
	body.setPosition(position);
	this->Owncolorbool = false;
}

void CreateYourOwnColorButton::Update(sf::RenderWindow& window, sf::Color maincolor)
{
	sf::Vector2f hoversize(size.x + 20.0f, size.y + 20.0f);
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < body.getGlobalBounds().left + body.getGlobalBounds().width && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < body.getGlobalBounds().top + body.getGlobalBounds().height)
	{
		body.setSize(hoversize);
		body.setOrigin(sf::Vector2f(hoversize.x / 2, hoversize.y / 2));

		this->Owncolorbool = !this->Owncolorbool;

	}
	else
	{
		body.setSize(size);
		body.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	}
	body.setFillColor(maincolor);
}

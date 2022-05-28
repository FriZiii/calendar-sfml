#include "ColorPalettes.h"

ColorPalettes::ColorPalettes(sf::Vector2f position, int colorIterator)
{
	this->colorIterator = colorIterator;
	this->position = position;
	body.setSize(sf::Vector2f(69.0f, 69.0f));
	body.setPosition(position);
	this->body.setFillColor(sf::Color(this->colors[colorIterator].x, this->colors[colorIterator].y, this->colors[colorIterator].z));
}

int ColorPalettes::getColorR(sf::RenderWindow& window)
{
	int R = colors[colorIterator].x;

		if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				return R;
			}
		}
}

int ColorPalettes::getColorG(sf::RenderWindow& window)
{
	int G = colors[colorIterator].y;

		if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				return G;
			}
		}
}

int ColorPalettes::getColorB(sf::RenderWindow& window)
{
	int B = colors[colorIterator].z;

		if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				return B;
			}
		}
}

#include "ColorPalettes.h"

ColorPalettes::ColorPalettes(sf::Vector2f position, int colorIterator)
{
	this->colorIterator = colorIterator;
	this->position = position;
	this->size = sf::Vector2f(70.0f, 70.0f);
	body.setSize(size);
	body.setPosition(position);
	body.setOrigin(sf::Vector2f(body.getSize().x / 2.0f, body.getSize().y / 2.0f));
	this->body.setFillColor(sf::Color(this->colors[colorIterator].x, this->colors[colorIterator].y, this->colors[colorIterator].z));
}

void ColorPalettes::Update(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		this->body.setSize(sf::Vector2f(size.x + 10.0f, size.y+10.0f));
		body.setOrigin(sf::Vector2f(body.getSize().x / 2.0f, body.getSize().y / 2.0f));
	}
	else
	{
		this->body.setSize(size);
		body.setOrigin(sf::Vector2f(body.getSize().x / 2.0f, body.getSize().y / 2.0f));
	}
}

bool ColorPalettes::isHover(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > body.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (body.getGlobalBounds().left + body.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > body.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (body.getGlobalBounds().top + body.getGlobalBounds().height))
	{
		return true;
	}
	return false;
}

int ColorPalettes::getColorR(sf::RenderWindow& window)
{
	int R = colors[colorIterator].x;

	return R;
}

int ColorPalettes::getColorG(sf::RenderWindow& window)
{
	int G = colors[colorIterator].y;

	return G;
}

int ColorPalettes::getColorB(sf::RenderWindow& window)
{
	int B = colors[colorIterator].z;

	return B;

}

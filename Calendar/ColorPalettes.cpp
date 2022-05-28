#include "ColorPalettes.h"

ColorPalettes::ColorPalettes(sf::Vector2f position, int colorIterator)
{
	this->colorIterator = colorIterator;
	this->position = position;
	body.setSize(sf::Vector2f(69.0f, 69.0f));
	body.setPosition(position);
	this->body.setFillColor(sf::Color(this->colors[colorIterator].x, this->colors[colorIterator].y, this->colors[colorIterator].z));
}

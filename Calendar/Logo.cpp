#include "Logo.h"

Logo::Logo(sf::Vector2f position, sf::Vector2f size, std::string file)
{
	this->position = position;
	this->size = size;
	this->file = file;
	this->texture.loadFromFile(file);
	body.setSize(sf::Vector2f(size));
	body.setPosition(sf::Vector2f(position.x - (body.getSize().x / 2.0f), position.y));
	body.setTexture(&texture);
}

#include "Logo.h"

Logo::Logo()
{
	this->texture.loadFromFile("Assets/Logo.png");
	body.setSize(sf::Vector2f(105.f, 105.f));
	body.setPosition(sf::Vector2f(133.0f - (105.f / 2.0f), 45.0f));
	body.setTexture(&texture);
}

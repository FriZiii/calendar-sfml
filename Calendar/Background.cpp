#include "Background.h"

Background::Background()
{
	body.setSize(sf::Vector2f(1200.0f, 610.0f));
	body.setPosition(sf::Vector2f(0.0f, 0.0f));

	this->texture.loadFromFile("Assets/Background.png");
	body.setTexture(&texture);
}

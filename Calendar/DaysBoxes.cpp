#include "DaysBoxes.h"

DaysBoxes::DaysBoxes(sf::Vector2f position)
{
	body.setSize(sf::Vector2f(67.63f, 58.18f));
	this->grey = sf::Color(232, 232, 232);
	this->position = position;
	body.setFillColor(grey);
	body.setPosition(position);
}

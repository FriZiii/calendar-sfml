#include "SidePanel.h"

SidePanel::SidePanel(sf::Vector2f size, sf::Vector2f position)
{
	this->size = size;
	this->position = position;
	body.setSize(size);
	body.setPosition(position);
	sf::Color Purple(93, 9, 172);
	body.setFillColor(Purple);
}

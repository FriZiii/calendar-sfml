#include "SidePanel.h"

SidePanel::SidePanel(sf::Vector2f size, sf::Vector2f position, sf::Color maincolor)
{
	this->size = size;
	this->position = position;
	body.setSize(size);
	body.setPosition(position);
	body.setFillColor(maincolor);
}

sf::Vector2f SidePanel::GetSize()
{
	return this->size;
}

sf::Vector2f SidePanel::GetPosition()
{
	return this->position;
}

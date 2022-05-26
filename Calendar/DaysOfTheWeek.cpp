#include "DaysOfTheWeek.h"

DaysOfTheWeek::DaysOfTheWeek(int i, sf::Vector2f position, sf::Font &font)
{
	this->possition = position;
	this->black = sf::Color(0, 0, 0);

	//An invisible box that helps to set the text positions
	box.setSize(sf::Vector2f(67.63f, 32.0f));
	box.setPosition(position);
	box.setFillColor(sf::Color(0, 0, 0, 0));

	text.setFont(font);
	text.setCharacterSize(16);
	text.setFillColor(black);
	text.setString(textString[i]);

	text.setPosition(box.getPosition().x + (box.getSize().x / 2.0f) - (text.getGlobalBounds().width /2.0f), box.getPosition().y+ (box.getSize().y / 2.0f) - (text.getGlobalBounds().height / 2.0f));
}

void DaysOfTheWeek::Draw(sf::RenderWindow& window)
{
	window.draw(box);
	window.draw(text);
}

#include "DaysOfTheWeek.h"

DaysOfTheWeek::DaysOfTheWeek(int i, sf::Vector2f position, sf::Font &font)
{
	this->possition = position;
	this->black = sf::Color(0, 0, 0);

	box.setSize(sf::Vector2f(67.63f, 32.0f));
	box.setPosition(position);
	box.setFillColor(sf::Color(0, 0, 0, 0));

	switch (i)
	{
	case 0:
		this->textString = "MON";
		break;
	case 1:
		this->textString = "TUE";
		break;
	case 2:
		this->textString = "WED";
		break;
	case 3:
		this->textString = "THU";
		break;
	case 4:
		this->textString = "FRI";
		break;
	case 5:
		this->textString = "SAT";
		break;
	case 6:
		this->textString = "SUN";
		break;
	}

	text.setFont(font);
	text.setCharacterSize(16);
	text.setFillColor(black);
	text.setString(textString);

	text.setPosition(box.getPosition().x + (box.getSize().x / 2.0f) - (text.getGlobalBounds().width /2.0f), box.getPosition().y+ (box.getSize().y / 2.0f) - (text.getGlobalBounds().height / 2.0f));
}

void DaysOfTheWeek::Draw(sf::RenderWindow& window)
{
	window.draw(box);
	window.draw(text);
}

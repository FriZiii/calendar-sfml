#include "DaysOfTheWeek.h"

DaysOfTheWeek::DaysOfTheWeek(int i, sf::Vector2f position)
{
	black = sf::Color(0, 0, 0);
	this->possition = position;
	text.setPosition(position);
	if (i == 0)
		this->textString = "MON";
	else if (i == 1)
		this->textString = "TUE";
	else if (i == 2)
		this->textString = "WED";
	else if (i == 3)
		this->textString = "THU";
	else if (i == 4)
		this->textString = "FRI";
	else if (i == 5)
		this->textString = "SAT";
	else if (i == 6)
		this->textString = "SUN";
}

void DaysOfTheWeek::Draw(sf::RenderWindow& window)
{
	font.loadFromFile("Fonts/WILD_WORLD.otf");
	text.setFont(font);
	text.setCharacterSize(16);
	text.setFillColor(black);
	text.setString(textString);
	window.draw(text);
}

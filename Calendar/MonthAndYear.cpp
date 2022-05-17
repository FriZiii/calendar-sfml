#include "MonthAndYear.h"

MonthAndYear::MonthAndYear(int month, int year, sf::Font &font)
{
	this->month = month;
	this->year = year;

	textStringYear = std::to_string(year);

	this->font = font;

	//Month
	sf::Color Purple(93, 9, 172);

	textMonth.setFont(font);
	textMonth.setCharacterSize(42);
	textMonth.setFillColor(Purple);

		//Auto capslock
	for (auto& c : textStringMonth[month]) c = toupper(c);
	textMonth.setString(textStringMonth[month]);

	textMonth.setPosition(601.0f - (textMonth.getGlobalBounds().width), (83.0f/2.0f) - (textMonth.getGlobalBounds().height/2.0f));

	//Year
	textYear.setFont(font);
	textYear.setCharacterSize(42);
	textYear.setFillColor(sf::Color::Black);
	textYear.setString(textStringYear);

	textYear.setPosition(601.0f, (83.0f / 2.0f) - (textYear.getGlobalBounds().height / 2.0f));

	//Buttons

	this->texture.loadFromFile("Assets/MonthYearButtons.png");
	buttonLeft.setSize(sf::Vector2f(40.0f, 40.0f));
	buttonLeft.setTexture(&texture);
	buttonLeft.setTextureRect(sf::IntRect(0, 0, 130, 148));
	buttonLeft.setPosition(textMonth.getPosition().x - buttonLeft.getSize().x - 10.0f, (83.0f / 2.0f) - (buttonLeft.getSize().y / 2.0f) + 5.0f);
}

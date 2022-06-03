#include "MonthAndYear.h"

MonthAndYear::MonthAndYear(int month, int year, sf::Font &font, sf::Color maincolor)
{
	this->month = month;
	this->year = year;
	this->font = font;

	//Month

	textMonth.setFont(font);
	textMonth.setCharacterSize(42);
	textMonth.setFillColor(maincolor);

	textMonth.setString(textStringMonth[month]);

	textMonth.setPosition(590.5f - (textMonth.getGlobalBounds().width) - 10.0f , (83.0f / 2.0f) - (textMonth.getGlobalBounds().height / 2.0f));

	//Year
	textStringYear = std::to_string(year);
	textYear.setFont(font);
	textYear.setCharacterSize(42);
	textYear.setFillColor(sf::Color::Black);
	textYear.setString(textStringYear);

	textYear.setPosition(590.5f + 10.0f, (83.0f / 2.0f) - (textYear.getGlobalBounds().height / 2.0f));

	//Buttons

		this->grey = sf::Color(232, 232, 232);

		//Right
		buttonRight.setPointCount(3);
		buttonRight.setPoint(0, sf::Vector2f(46.0f / 10.0f, 400.0f / 10.0f));
		buttonRight.setPoint(1, sf::Vector2f(-300.0f / 10.0f, 200.0f / 10.0f));
		buttonRight.setPoint(2, sf::Vector2f(- 300.0f / 10.0f, 600.0f / 10.0f));

		buttonRight.setFillColor(grey);
		buttonRight.setPosition(590.5f + 250.0f, (83.0f / 2.0f) - (buttonRight.getGlobalBounds().height) + 6.0f);

		//Left
		buttonLeft.setPointCount(3);
		buttonLeft.setPoint(0, sf::Vector2f(-46.0f/10.0f, 400.0f/10.0f));
		buttonLeft.setPoint(1, sf::Vector2f(300.0f/10.0f, 200.0f/10.0f));
		buttonLeft.setPoint(2, sf::Vector2f(300.0f/10.0f, 600.0f/10.0f));

		buttonLeft.setFillColor(grey);
		buttonLeft.setPosition(590.5f - 250.0f, (83.0f / 2.0f) - (buttonLeft.getGlobalBounds().height) + 6.0f);
}

void MonthAndYear::Update(sf::RenderWindow& window, sf::Color maincolor)
{
	textMonth.setFillColor(maincolor);

	//Left
	if (sf::Mouse::getPosition(window).x > buttonLeft.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (buttonLeft.getGlobalBounds().left + buttonLeft.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > buttonLeft.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (buttonLeft.getGlobalBounds().top + buttonLeft.getGlobalBounds().height))
	{
		this->month--;
		if (month < 1)
		{
			month = 12;
			year--;
			textStringYear = std::to_string(year);
			textYear.setString(textStringYear);
			textYear.setPosition(590.5f + 10.0f, (83.0f / 2.0f) - (textYear.getGlobalBounds().height / 2.0f));
		}
		textMonth.setString(textStringMonth[month]);
		textMonth.setPosition(590.5f - (textMonth.getGlobalBounds().width) - 10.0f, (83.0f / 2.0f) - (textMonth.getGlobalBounds().height / 2.0f));
	}

	//Right
	if (sf::Mouse::getPosition(window).x > buttonRight.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (buttonRight.getGlobalBounds().left + buttonRight.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > buttonRight.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (buttonRight.getGlobalBounds().top + buttonRight.getGlobalBounds().height))
	{
		this->month++;
		if (month > 12)
		{
			month = 1;
			year++;
			textStringYear = std::to_string(year);
			textYear.setString(textStringYear);
			textYear.setPosition(590.5f + 10.0f, (83.0f / 2.0f) - (textYear.getGlobalBounds().height / 2.0f));
		}
		textMonth.setString(textStringMonth[month]);
		textMonth.setPosition(590.5f - (textMonth.getGlobalBounds().width) - 10.0f, (83.0f / 2.0f) - (textMonth.getGlobalBounds().height / 2.0f));
	}
}


void MonthAndYear::HoverEffect(sf::RenderWindow& window, sf::Color maincolor)
{
	//Left
	if (sf::Mouse::getPosition(window).x > buttonLeft.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (buttonLeft.getGlobalBounds().left + buttonLeft.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > buttonLeft.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (buttonLeft.getGlobalBounds().top + buttonLeft.getGlobalBounds().height))
	{
		buttonLeft.setFillColor(maincolor);
	}
	else
	{
		buttonLeft.setFillColor(grey);
	}

	//Right
	if (sf::Mouse::getPosition(window).x > buttonRight.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (buttonRight.getGlobalBounds().left + buttonRight.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > buttonRight.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (buttonRight.getGlobalBounds().top + buttonRight.getGlobalBounds().height))
	{
		buttonRight.setFillColor(maincolor);
	}
	else
	{
		buttonRight.setFillColor(grey);
	}
}

std::string MonthAndYear::GetMonthString()
{
	return textStringMonth[month];
}

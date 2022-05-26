#include "MonthAndYear.h"

MonthAndYear::MonthAndYear(int month, int year, sf::Font &font)
{
	this->month = month;
	this->year = year;
	this->font = font;

	//Month
	sf::Color Purple(93, 9, 172);

	textMonth.setFont(font);
	textMonth.setCharacterSize(42);
	textMonth.setFillColor(Purple);

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

		//Right
		this->texture.loadFromFile("Assets/MonthYearButtons.png");
		buttonRight.setSize(sf::Vector2f(30.0f, 30.0f));
		buttonRight.setTexture(&texture);
		buttonRight.setTextureRect(sf::IntRect(0, 0, 135, 152));
		buttonRight.setPosition(590.5f + 250.0f, (83.0f / 2.0f) - (buttonRight.getSize().y / 2.0f) + 6.0f);

		//Left
		this->texture.loadFromFile("Assets/MonthYearButtons.png");
		buttonLeft.setSize(sf::Vector2f(30.0f, 30.0f));
		buttonLeft.setTexture(&texture);
		buttonLeft.setTextureRect(sf::IntRect(135, 0, 135, 152));
		buttonLeft.setPosition(590.5f - 250.0f, (83.0f / 2.0f) - (buttonLeft.getSize().y / 2.0f) + 6.0f);
}

void MonthAndYear::Update(sf::RenderWindow& window)
{
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

void MonthAndYear::HoverEffect(sf::RenderWindow& window)
{
	//Left
	if (sf::Mouse::getPosition(window).x > buttonLeft.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (buttonLeft.getGlobalBounds().left + buttonLeft.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > buttonLeft.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (buttonLeft.getGlobalBounds().top + buttonLeft.getGlobalBounds().height))
	{
		buttonLeft.setTextureRect(sf::IntRect(135, 152, 135, 152));
	}
	else
	{
		buttonLeft.setTextureRect(sf::IntRect(135, 0, 135, 152));
	}

	//Right
	if (sf::Mouse::getPosition(window).x > buttonRight.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (buttonRight.getGlobalBounds().left + buttonRight.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > buttonRight.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (buttonRight.getGlobalBounds().top + buttonRight.getGlobalBounds().height))
	{
		buttonRight.setTextureRect(sf::IntRect(0, 152, 135, 152));
	}
	else
	{
		buttonRight.setTextureRect(sf::IntRect(0, 0, 135, 152));
	}
}

std::string MonthAndYear::GetMonthString()
{
	return textStringMonth[month];
}

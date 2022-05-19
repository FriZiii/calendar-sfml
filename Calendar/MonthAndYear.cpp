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

	textMonth.setPosition(601.0f - (textMonth.getGlobalBounds().width), (83.0f/2.0f) - (textMonth.getGlobalBounds().height/2.0f));

	//Year
	textStringYear = std::to_string(year);
	textYear.setFont(font);
	textYear.setCharacterSize(42);
	textYear.setFillColor(sf::Color::Black);
	textYear.setString(textStringYear);

	textYear.setPosition(601.0f, (83.0f / 2.0f) - (textYear.getGlobalBounds().height / 2.0f));

	//Buttons

		//Right

		this->texture.loadFromFile("Assets/MonthYearButtons.png");
		buttonRight.setSize(sf::Vector2f(30.0f, 30.0f));
		buttonRight.setTexture(&texture);
		buttonRight.setTextureRect(sf::IntRect(0, 0, 135, 152));
		buttonRight.setPosition((textYear.getPosition().x + textYear.getGlobalBounds().width) + buttonRight.getSize().x + 10.0f, (83.0f / 2.0f) - (buttonRight.getSize().y / 2.0f) + 6.0f);

		//Left

		this->texture.loadFromFile("Assets/MonthYearButtons.png");
		buttonLeft.setSize(sf::Vector2f(30.0f, 30.0f));
		buttonLeft.setTexture(&texture);
		buttonLeft.setTextureRect(sf::IntRect(135, 0, 135, 152));
		buttonLeft.setPosition((textMonth.getPosition().x) - buttonLeft.getSize().x - 10.0f, (83.0f / 2.0f) - (buttonLeft.getSize().y / 2.0f) + 6.0f);
}

void MonthAndYear::Update(sf::RenderWindow& window)
{
	sf::Event event{};

	if (sf::Mouse::getPosition(window).x > buttonLeft.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (buttonLeft.getGlobalBounds().left + buttonLeft.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > buttonLeft.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (buttonLeft.getGlobalBounds().top + buttonLeft.getGlobalBounds().height))
	{
		buttonLeft.setTextureRect(sf::IntRect(135, 152, 135, 152));

		if (window.pollEvent(event))
		{
			if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				this->month--;
				if (month < 1)
				{
					month = 12;
					year--;
					textStringYear = std::to_string(year);
					textYear.setString(textStringYear);
				}
				textMonth.setString(textStringMonth[month]);
			}
		}

	}
	else
	{
		buttonLeft.setTextureRect(sf::IntRect(135, 0, 135, 152));
	}

	if (sf::Mouse::getPosition(window).x > buttonRight.getGlobalBounds().left && sf::Mouse::getPosition(window).x < (buttonRight.getGlobalBounds().left + buttonRight.getGlobalBounds().width) && sf::Mouse::getPosition(window).y > buttonRight.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (buttonRight.getGlobalBounds().top + buttonRight.getGlobalBounds().height))
	{
		buttonRight.setTextureRect(sf::IntRect(0, 152, 135, 152));
		
		if (window.pollEvent(event))
		{
			if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				this->month++;
				if (month > 12)
				{
					month = 1;
					year++;
					textStringYear = std::to_string(year);
					textYear.setString(textStringYear);
				}
				textMonth.setString(textStringMonth[month]);
			}
		}
	}
	else
	{
		buttonRight.setTextureRect(sf::IntRect(0, 0, 135, 152));
	}
}

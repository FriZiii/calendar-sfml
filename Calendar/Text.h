#pragma once
#include <SFML/Graphics.hpp>
class Text
{
	sf::Text text;
	sf::Text text2;
	sf::Text coloredText;

	std::string textString;
	std::string textString2;
	std::string coloredtextString;

	sf::Vector2f position;
	sf::Font font;
public:
	//For settings
	Text(std::string textString, sf::Vector2f position, sf::Font &font, int fontSize);

	//For credits
	Text(std::string coloredtextString, std::string textString, sf::Vector2f position, sf::Font& font, sf::Color maincolor, int fontSize);
	Text(std::string textString1, std::string coloredtextString, std::string textString2, sf::Vector2f position, sf::Font& font, sf::Color maincolor, int fontSize);

	void Draw(sf::RenderWindow& window) { window.draw(text); window.draw(coloredText); window.draw(text2); }
	void Update(sf::Color maincolor);
};


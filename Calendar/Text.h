#pragma once
#include <SFML/Graphics.hpp>
class Text
{
	sf::Text text;
	sf::Text coloredText;

	std::string textString;
	std::string coloredtextString;

	sf::Vector2f position;
	sf::Font font;
public:
	Text(std::string textString, sf::Vector2f position, sf::Font &font, int fontSize);
	Text(std::string textString, sf::Vector2f position, sf::Font &font, std::string coloredtextString, sf::Color maincolor, int fontSize);
	void Draw(sf::RenderWindow& window) { window.draw(text); window.draw(coloredText);}
	void Update(sf::Color maincolor);
};


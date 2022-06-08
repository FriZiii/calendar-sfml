#pragma once
#include <SFML/Graphics.hpp>
class ColorPalettes
{
	sf::RectangleShape body;
	sf::Vector2f position;
	sf::Vector2f size;
	
	int colorIterator;
	sf::Color color;

	sf::Vector3i colors[10] = {
		sf::Vector3i/*
					*/(161, 2, 32),           sf::Vector3i /*
					
					light*/(205, 12, 43),
		sf::Vector3i /*orange*/(232, 93, 4),       sf::Vector3i /*yellow*/(255, 186, 8),
		sf::Vector3i /*greenlight*/(67, 168, 72),  sf::Vector3i /*green*/(27, 133, 57),
		sf::Vector3i /*bluelight*/ (0, 104, 175),  sf::Vector3i /*blue*/(0, 62, 127),
		sf::Vector3i /*purple*/(93, 9, 172),       sf::Vector3i /*pink*/(179, 51, 233),
	};

public:
	ColorPalettes(sf::Vector2f position, int colorIterator);
	void Draw(sf::RenderWindow& window) { window.draw(body); }
	void Update(sf::RenderWindow & window);
	bool isHover(sf::RenderWindow& window);
	int getColorR(sf::RenderWindow& window);
	int getColorG(sf::RenderWindow& window);
	int getColorB(sf::RenderWindow& window);

};
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
class InputOutputManager
{
	std::string input{};
	std::string output{};
	std::fstream file{};

	int year;
	int month;
	int day;

	std::string returningFileName;

public:
	bool foundFile(int year, int month, int day);
	void DrawTextFromFile(int year, int month, int day, sf::Font& font, sf::RenderWindow& window, sf::Color maincolor);
	void SaveEventToFile(int year, int month, int day, std::string &input);
	std::string GetFileName(int year, int month, int day);
};


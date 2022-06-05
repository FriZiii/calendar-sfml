#pragma once
#include <iostream>
#include <fstream>
#include <string>
class InputOutputManager
{
	std::string input{};
	std::string output{};
	std::fstream file{};

	int year;
	int month;
	int day;

public:
	bool foundFile(int year, int month, int day);
};


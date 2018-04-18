#pragma once
#include "GeographicArea.h"
#include "LandArea.h"
#include "WaterArea.h"
#include "Country.h"
#include "Tests.h"

///funkcja menu, która stanowi konsolowy interfejs
void menu()
{
	std::cout << std::endl;
	std::cout << "Author: Karolina Pawluk\n";
	std::cout << "This project is managing Countries\n\n";

	int number = 0;

	while (number != 10)
	{
		std::cout << "Which test do you want to run?\n";
		std::cout << "0 - All classes tests\n";
		std::cout << "1 - WaterArea Class Test\n2 - LandArea Class Test\n3 - Country Class Test\n";
		std::cout << "4 - Save WaterArea Class to file\n5 - Save LandArea Class to file\n";
		std::cout << "6 - Save Country Class to file\n";
		std::cout << "7 - Read WaterArea Class from file\n8 - Read LandArea Class from file\n";
		std::cout << "9 - Read Country Class from file\n";
		std::cout << "10 - Quit\n";
		std::cin >> number;

		switch (number)
		{
		case 0:
			std::cout << "The class tests are going to start now...\n\n";
			std::cout << "..............................\n\n";
			automaticTests::allClassesTest();
			break;
		case 1:
			std::cout << "The class tests are going to start now...\n\n";
			std::cout << "..............................\n\n";
			automaticTests::waterAreaTest();
			break;
		case 2:
			std::cout << "The class tests are going to start now...\n\n";
			std::cout << "..............................\n\n";
			automaticTests::landAreaTest();
			break;
		case 3:
			std::cout << "The class tests are going to start now...\n\n";
			std::cout << "..............................\n\n";
			automaticTests::countryTest();
			break;
		case 4:
			std::cout << "Saving class to file...\n\n";
			std::cout << "..............................\n\n";
			writeToFileTests::waterAreaTest();
			break;
		case 5:
			std::cout << "Saving class to file...\n\n";
			std::cout << "..............................\n\n";
			writeToFileTests::landAreaTest();
			break;
		case 6:
			std::cout << "Saving class to file...\n\n";
			std::cout << "..............................\n\n";
			writeToFileTests::countryTest();
			break;
		case 7:
			std::cout << "Reading class from file...\n\n";
			std::cout << "..............................\n\n";
			readFromFileTests::waterAreaTest();
			break;
		case 8:
			std::cout << "Reading class from file...\n\n";
			std::cout << "..............................\n\n";
			readFromFileTests::landAreaTest();
			break;
		case 9:
			std::cout << "Reading class from file...\n\n";
			std::cout << "..............................\n\n";
			readFromFileTests::countryTest();
			break;
		case 10:
			break;
		default:
			std::cout << "Wrong number! Try again\n";
			break;
		}
	}
}
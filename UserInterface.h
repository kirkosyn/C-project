#pragma once

#include <iostream>
#include "Country.h"
#include "Tests.h"

///funkcje testuj¹ce klasy Country
void countryClassTests()
{
	dynamicTests::countryTest();
	automaticTests::countryTest();
	staticTests::countryTest();
}
///funkcje testuj¹ce klasy Citizen
void citizenClassTests()
{
	dynamicTests::citizenTest();
	automaticTests::citizenTest();
	staticTests::citizenTest();
}
///funkcje testuj¹ce klasy Town
void townClassTests()
{
	dynamicTests::townTest();
	automaticTests::townTest();
	staticTests::townTest();
}
///funkcje testuj¹ce klasy PartnerCountry
void partnerCountryClassTests()
{
	dynamicTests::partnerCountryTest();
	automaticTests::partnerCountryTest();
	staticTests::partnerCountryTest();
}

///funkcja menu, która stanowi konsolowy interfejs
void menu()
{
	std::cout << std::endl;
	std::cout << "Author: Karolina Pawluk\n";
	std::cout << "This project is managing Countries\n\n";

	int number = 0;

	while (number != 5)
	{
		std::cout << "Which test do you want to run?\n1 - Citizen Class Test\n"
			<< "2 - Town Class Test\n3 - Partner Country Class Test\n4 - Country Class Test\n5 - Quit\n";
		std::cin >> number;
		switch (number)
		{
		case 1:
			std::cout << "The class tests are going to start now...\n\n";
			std::cout << "..............................\n\n";
			citizenClassTests();
			break;
		case 2:
			std::cout << "The class tests are going to start now...\n\n";
			std::cout << "..............................\n\n";
			townClassTests();
			break;
		case 3:
			std::cout << "The class tests are going to start now...\n\n";
			std::cout << "..............................\n\n";
			partnerCountryClassTests();
			break;
		case 4:
			std::cout << "The class tests are going to start now...\n\n";
			std::cout << "..............................\n\n";
			countryClassTests();
			break;
		case 5:
			break;
		default:
			std::cout << "Wrong number! Try again\n";
			break;
		}
	}
}
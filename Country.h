#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Citizen.h"
#include "PartnerCountry.h"
#include "Town.h"
#include "LandArea.h"

class Country: public LandArea
{
private:
	///sta�a zmienna przechowuj�ca maksymaln� liczb� kraj�w
	static const int MAX_AMOUNT_OF_COUNTRIES = 15;
	///sta�a zmienna przechowuj�ca maksymaln� liczb� mieszka�c�w
	static const int MAX_AMOUNT_OF_CITIZENS = 15;
	///sta�a zmienna przechowuj�ca maksymaln� liczb� miast
	static const int MAX_AMOUNT_OF_TOWNS = 15;

	///zmienna przechowuj�ca nazw� kraju
	std::string name;
	///zmienna statyczna przechowuj�ca liczb� kraj�w
	static int amount_of_countries;
	///zmienna statyczna przechowuj�ca liczb� mieszka�c�w
	static int amount_of_citizens;
	///zmienna statyczna przechowuj�ca liczb� miast
	static int amount_of_towns;
	//double area;

	///vector przechowuj�cy obiekty klasy Citizen
	std::vector<Citizen> citizenArray;
	///vector przechowuj�cy obiekty klasy Town
	std::vector<Town> townArray;
	///zmienna przechowuj�ca obiekt klasy PartnerCountry
	PartnerCountry partner;

public:
	// constructors
	///konstruktor domy�lny
	Country();
	///konstruktor z parametrami przyjmuj�cy nazw� kraju, powierzchni�, obiekt klasy PartnerCountry
	Country(std::string, double, PartnerCountry &);
	///konstruktor kopiuj�cy
	Country(const Country &);  // copy constructor

	// getting private members
	///funkcja zwracaj�ca warto�� pola private name
	std::string getName();
	///funkcja zwracaj�ca warto�� pola private partner
	PartnerCountry getPartner() const;
	///funkcja zwracaj�ca warto�� pola private amount_of_countries
	static int getAmountOfCountries();
	///funkcja zwracaj�ca warto�� pola private amount_of_citizens
	static int getAmountOfCitizens();
	///funkcja zwracaj�ca warto�� pola private amount_of_towns
	static int getAmountOfTowns();
	//double getArea();
	//Citizen *getCitizen() const;
	//Town *getTown() const;

	// setting private members
	///funkcja ustawiaj�ca warto�� pola private partner
	void setPartner(PartnerCountry &);
	///funkcja ustawiaj�ca warto�� pola private name
	void setName(std::string);
	///funkcja ustawiaj�ca warto�� pola private area
	void setArea(double);

	// operators  
	///operator indeksowania []
	void operator[](int);  //operator []
	///operator por�wnania ==
	bool operator==(Country &); // operator ==
	///operator por�wnania >
	bool operator>(Country &) const;  // operator >
	
	///operator strumienia wyj�cia - zapis do pliku
	friend std::ostream& operator<< (std::ostream &, Country &);  // operator <<
	///operator strumienia wej�cia - odczyt z pliku
	friend std::istream& operator>> (std::istream &, Country &);  // operator >>

	// methods
	///metoda przypisuj�ca powierzchni�
	void assignArea(double, double);
	///metoda wypisuj�ca na ekran, kto zamieszkuje kraje
	void whoLives();
	///metoda wpisuj�ca na ekran stan ca�ego obiektu klasy Country
	void showCountry();
	///metoda dodaj�ca mieszka�ca do kraju
	Country addCitizen(Country &, Citizen &);
	///metoda dodaj�ca miasto do kraju
	Country addTown(Country &, Town &);
	///metoda usuwaj�ca mieszka�ca z kraju
	Country eraseCitizen();
	///metoda usuwaj�ca miasto z kraju
	Country eraseTown();

	///destruktor
	~Country();
};


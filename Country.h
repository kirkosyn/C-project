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
	///sta³a zmienna przechowuj¹ca maksymaln¹ liczbê krajów
	static const int MAX_AMOUNT_OF_COUNTRIES = 15;
	///sta³a zmienna przechowuj¹ca maksymaln¹ liczbê mieszkañców
	static const int MAX_AMOUNT_OF_CITIZENS = 15;
	///sta³a zmienna przechowuj¹ca maksymaln¹ liczbê miast
	static const int MAX_AMOUNT_OF_TOWNS = 15;

	///zmienna przechowuj¹ca nazwê kraju
	std::string name;
	///zmienna statyczna przechowuj¹ca liczbê krajów
	static int amount_of_countries;
	///zmienna statyczna przechowuj¹ca liczbê mieszkañców
	static int amount_of_citizens;
	///zmienna statyczna przechowuj¹ca liczbê miast
	static int amount_of_towns;
	//double area;

	///vector przechowuj¹cy obiekty klasy Citizen
	std::vector<Citizen> citizenArray;
	///vector przechowuj¹cy obiekty klasy Town
	std::vector<Town> townArray;
	///zmienna przechowuj¹ca obiekt klasy PartnerCountry
	PartnerCountry partner;

public:
	// constructors
	///konstruktor domyœlny
	Country();
	///konstruktor z parametrami przyjmuj¹cy nazwê kraju, powierzchniê, obiekt klasy PartnerCountry
	Country(std::string, double, PartnerCountry &);
	///konstruktor kopiuj¹cy
	Country(const Country &);  // copy constructor

	// getting private members
	///funkcja zwracaj¹ca wartoœæ pola private name
	std::string getName();
	///funkcja zwracaj¹ca wartoœæ pola private partner
	PartnerCountry getPartner() const;
	///funkcja zwracaj¹ca wartoœæ pola private amount_of_countries
	static int getAmountOfCountries();
	///funkcja zwracaj¹ca wartoœæ pola private amount_of_citizens
	static int getAmountOfCitizens();
	///funkcja zwracaj¹ca wartoœæ pola private amount_of_towns
	static int getAmountOfTowns();
	//double getArea();
	//Citizen *getCitizen() const;
	//Town *getTown() const;

	// setting private members
	///funkcja ustawiaj¹ca wartoœæ pola private partner
	void setPartner(PartnerCountry &);
	///funkcja ustawiaj¹ca wartoœæ pola private name
	void setName(std::string);
	///funkcja ustawiaj¹ca wartoœæ pola private area
	void setArea(double);

	// operators  
	///operator indeksowania []
	void operator[](int);  //operator []
	///operator porównania ==
	bool operator==(Country &); // operator ==
	///operator porównania >
	bool operator>(Country &) const;  // operator >
	
	///operator strumienia wyjœcia - zapis do pliku
	friend std::ostream& operator<< (std::ostream &, Country &);  // operator <<
	///operator strumienia wejœcia - odczyt z pliku
	friend std::istream& operator>> (std::istream &, Country &);  // operator >>

	// methods
	///metoda przypisuj¹ca powierzchniê
	void assignArea(double, double);
	///metoda wypisuj¹ca na ekran, kto zamieszkuje kraje
	void whoLives();
	///metoda wpisuj¹ca na ekran stan ca³ego obiektu klasy Country
	void showCountry();
	///metoda dodaj¹ca mieszkañca do kraju
	Country addCitizen(Country &, Citizen &);
	///metoda dodaj¹ca miasto do kraju
	Country addTown(Country &, Town &);
	///metoda usuwaj¹ca mieszkañca z kraju
	Country eraseCitizen();
	///metoda usuwaj¹ca miasto z kraju
	Country eraseTown();

	///destruktor
	~Country();
};


#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "GeographicArea.h"

///typy rzeŸby terenu
enum type_of_landforms { BAY, COAST, LAGOON, CHANNEL, OCEANIC_TRENCH };

class WaterArea: public GeographicArea
{
private:
	///zmienna przechowuj¹ca typ wody: "Sweet_water" lub "Salt_water"
	std::string typeOfWater;

public:
	// constructors
	///konstruktor domyœlny
	WaterArea();

	// getting private members
	///funkcja zwracaj¹ca wartoœæ pola private typeOfWater
	std::string getTypeOfWater();

	// getting protected members
	///funkcja zwracaj¹ca wartoœæ pola protected latitude klasy GeographicArea, do której mamy dostêp 
	int getLatitude();
	///funkcja zwracaj¹ca wartoœæ pola protected longitude klasy GeographicArea, do której mamy dostêp 
	int getLongitude();
	///funkcja zwracaj¹ca wartoœæ pola protected hemisphere klasy GeographicArea, do której mamy dostêp 
	std::string getHemisphere();

	// setting private members
	///funkcja ustawiaj¹ca wartoœæ pola prywatnego typeOfWater
	void setTypeOfWater(std::string);

	// setting object
	///funkcja ustawiaj¹ca losowo wartoœci pól private i protected obiektu klasy WaterArea
	void setObject();

	// methods
	///metoda przypisuj¹ca powierzchniê
	void assignArea(double, double);
	///metoda wypisuj¹ca na ekran, kto zamieszkuje tereny wodne
	void whoLives();
	///metoda wpisuj¹ca na ekran stan ca³ego obiektu klasy WaterArea
	void showArea();
	///metoda zwracaj¹ca rzeŸbê terenu
	std::string whichLandform(int);
	///metoda zwracaj¹ca losowy typ wody typeOfWater
	std::string randomType();

	// operators
	///operator strumienia wyjœcia - zapis do pliku
	friend std::ostream& operator<< (std::ostream &, WaterArea &);
	///operator strumienia wejœcia - odczyt z pliku
	friend std::istream& operator>> (std::istream &, WaterArea &);
	
	///desktruktor
	~WaterArea();
};

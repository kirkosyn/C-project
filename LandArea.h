#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "GeographicArea.h"

///typy rzeŸby terenu
enum list_of_landforms { MOUNTAIN, VALLEY, TUNDRA, CAVE, DESERT, ISLAND, PLAIN };

class LandArea: public GeographicArea
{
private:
	///zmienna przechowuj¹ca wartoœæ 0 lub 1, która informuje o tym, czy dana ziemia nadaje siê pod uprawy
	int suitable;

public:
	// constructors
	///konstruktor domyœlny
	LandArea();

	// getting protected members
	///funkcja zwracaj¹ca wartoœæ pola protected latitude klasy GeographicArea, do której mamy dostêp 
	int getLatitude();
	///funkcja zwracaj¹ca wartoœæ pola protected longitude klasy GeographicArea, do której mamy dostêp 
	int getLongitude();
	///funkcja zwracaj¹ca wartoœæ pola protected hemisphere klasy GeographicArea, do której mamy dostêp 
	std::string getHemisphere();
	///funkcja zwracaj¹ca wartoœæ pola protected area klasy GeographicArea, do której mamy dostêp
	double getArea();

	// setting protected members
	///funkcja ustawiaj¹ca wartoœæ pola protected continent
	void setContinent(std::string);
	///funkcja ustawiaj¹ca wartoœæ pola protected borders
	void setBorders(double);

	// setting object
	///funkcja ustawiaj¹ca losowo wartoœci pól private i protected obiektu klasy LandArea
	void setObject();

	// methods
	///metoda przypisuj¹ca powierzchniê
	void assignArea(double, double);
	///metoda wypisuj¹ca na ekran, kto zamieszkuje tereny l¹dowe
	void whoLives();
	///metoda wpisuj¹ca na ekran stan ca³ego obiektu klasy LandArea
	void showArea();
	///metoda zwracaj¹ca rzeŸbê terenu
	std::string whichLandform(int);
	///metoda zwracaj¹ca losow¹ nazwê kontynentu continent
	std::string randomContinent();
	///metoda wyznaczaj¹ca, czy dany obszar nadaje siê pod uprawy
	bool suitable_for_cultivation();

	// operators
	///operator strumienia wyjœcia - zapis do pliku
	friend std::ostream& operator<< (std::ostream &, LandArea &);
	///operator strumienia wejœcia - odczyt z pliku
	friend std::istream& operator>> (std::istream &, LandArea &);

	///destruktor
	~LandArea();

protected:
	///zmienna przechowuj¹ca nazwê kontynentu
	std::string continent;
	///zmienna przechowuj¹ca d³ugoœæ granic
	double borders;
};

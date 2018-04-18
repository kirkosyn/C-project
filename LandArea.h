#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "GeographicArea.h"

///typy rze�by terenu
enum list_of_landforms { MOUNTAIN, VALLEY, TUNDRA, CAVE, DESERT, ISLAND, PLAIN };

class LandArea: public GeographicArea
{
private:
	///zmienna przechowuj�ca warto�� 0 lub 1, kt�ra informuje o tym, czy dana ziemia nadaje si� pod uprawy
	int suitable;

public:
	// constructors
	///konstruktor domy�lny
	LandArea();

	// getting protected members
	///funkcja zwracaj�ca warto�� pola protected latitude klasy GeographicArea, do kt�rej mamy dost�p 
	int getLatitude();
	///funkcja zwracaj�ca warto�� pola protected longitude klasy GeographicArea, do kt�rej mamy dost�p 
	int getLongitude();
	///funkcja zwracaj�ca warto�� pola protected hemisphere klasy GeographicArea, do kt�rej mamy dost�p 
	std::string getHemisphere();
	///funkcja zwracaj�ca warto�� pola protected area klasy GeographicArea, do kt�rej mamy dost�p
	double getArea();

	// setting protected members
	///funkcja ustawiaj�ca warto�� pola protected continent
	void setContinent(std::string);
	///funkcja ustawiaj�ca warto�� pola protected borders
	void setBorders(double);

	// setting object
	///funkcja ustawiaj�ca losowo warto�ci p�l private i protected obiektu klasy LandArea
	void setObject();

	// methods
	///metoda przypisuj�ca powierzchni�
	void assignArea(double, double);
	///metoda wypisuj�ca na ekran, kto zamieszkuje tereny l�dowe
	void whoLives();
	///metoda wpisuj�ca na ekran stan ca�ego obiektu klasy LandArea
	void showArea();
	///metoda zwracaj�ca rze�b� terenu
	std::string whichLandform(int);
	///metoda zwracaj�ca losow� nazw� kontynentu continent
	std::string randomContinent();
	///metoda wyznaczaj�ca, czy dany obszar nadaje si� pod uprawy
	bool suitable_for_cultivation();

	// operators
	///operator strumienia wyj�cia - zapis do pliku
	friend std::ostream& operator<< (std::ostream &, LandArea &);
	///operator strumienia wej�cia - odczyt z pliku
	friend std::istream& operator>> (std::istream &, LandArea &);

	///destruktor
	~LandArea();

protected:
	///zmienna przechowuj�ca nazw� kontynentu
	std::string continent;
	///zmienna przechowuj�ca d�ugo�� granic
	double borders;
};

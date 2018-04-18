#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "GeographicArea.h"

///typy rze�by terenu
enum type_of_landforms { BAY, COAST, LAGOON, CHANNEL, OCEANIC_TRENCH };

class WaterArea: public GeographicArea
{
private:
	///zmienna przechowuj�ca typ wody: "Sweet_water" lub "Salt_water"
	std::string typeOfWater;

public:
	// constructors
	///konstruktor domy�lny
	WaterArea();

	// getting private members
	///funkcja zwracaj�ca warto�� pola private typeOfWater
	std::string getTypeOfWater();

	// getting protected members
	///funkcja zwracaj�ca warto�� pola protected latitude klasy GeographicArea, do kt�rej mamy dost�p 
	int getLatitude();
	///funkcja zwracaj�ca warto�� pola protected longitude klasy GeographicArea, do kt�rej mamy dost�p 
	int getLongitude();
	///funkcja zwracaj�ca warto�� pola protected hemisphere klasy GeographicArea, do kt�rej mamy dost�p 
	std::string getHemisphere();

	// setting private members
	///funkcja ustawiaj�ca warto�� pola prywatnego typeOfWater
	void setTypeOfWater(std::string);

	// setting object
	///funkcja ustawiaj�ca losowo warto�ci p�l private i protected obiektu klasy WaterArea
	void setObject();

	// methods
	///metoda przypisuj�ca powierzchni�
	void assignArea(double, double);
	///metoda wypisuj�ca na ekran, kto zamieszkuje tereny wodne
	void whoLives();
	///metoda wpisuj�ca na ekran stan ca�ego obiektu klasy WaterArea
	void showArea();
	///metoda zwracaj�ca rze�b� terenu
	std::string whichLandform(int);
	///metoda zwracaj�ca losowy typ wody typeOfWater
	std::string randomType();

	// operators
	///operator strumienia wyj�cia - zapis do pliku
	friend std::ostream& operator<< (std::ostream &, WaterArea &);
	///operator strumienia wej�cia - odczyt z pliku
	friend std::istream& operator>> (std::istream &, WaterArea &);
	
	///desktruktor
	~WaterArea();
};

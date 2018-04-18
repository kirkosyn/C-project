#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class GeographicArea
{
public:
	// constructors
	///konstruktor domy�lny
	GeographicArea();

	// virtual methods
	///wirtualna metoda przypisania powierzchni
	virtual void assignArea(double, double) = 0;
	///wirtualna metoda wypisuj�ca na ekran, kto mieszka na danym terenie
	virtual void whoLives() = 0;
	///wirtualna metoda wypisuj�ca na ekran stan obiektu
	virtual void showArea() = 0;
	///wirtualna metoda zwracaj�ca rze�b� terenu
	virtual std::string whichLandform(int) = 0;
	///wirtualna metoda przypisania losowych warto�ci do p�l obiektu
	virtual void setObject() = 0;

	// setting protected members
	///funkcja ustawiaj�ca warto�� pola protected latitude
	void setLatitude(int);
	///funkcja ustawiaj�ca warto�� pola protected longitude
	void setLongitude(int);
	///funkcja ustawiaj�ca warto�� pola protected hemisphere
	void setHemisphere(std::string);
	///funkcja ustawiaj�ca warto�� pola protected landform
	void setLandform(int);

	// methods
	///metoda zwracaj�ca losow� p�kul�
	std::string randomHemisphere();

	///destruktor
	~GeographicArea();

protected:
	///zmienna przechowuj�ca szeroko�� geograficzn� od 0 do 90 stopni
	int latitude;  // szerokosc geograficzna 0 - 90 stopni
	///zmienna przechowuj�ca d�ugo�� geograficzn� od 0 do 180 stopni
	int longitude;  // dlugosc geograficzna 0 - 180 stopni
	///zmienna przechowuj�ca p�kul�: "NE", "NW", "SE", "SW"
	std::string hemisphere;  // NE, NW, SE, SW
	///zmienna przechowuj�ca warto�� powierzchni
	double area;
	///zmienna przechowuj�ca rze�b� terenu
	int landform;
};
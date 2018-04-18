#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class GeographicArea
{
public:
	// constructors
	///konstruktor domyœlny
	GeographicArea();

	// virtual methods
	///wirtualna metoda przypisania powierzchni
	virtual void assignArea(double, double) = 0;
	///wirtualna metoda wypisuj¹ca na ekran, kto mieszka na danym terenie
	virtual void whoLives() = 0;
	///wirtualna metoda wypisuj¹ca na ekran stan obiektu
	virtual void showArea() = 0;
	///wirtualna metoda zwracaj¹ca rzeŸbê terenu
	virtual std::string whichLandform(int) = 0;
	///wirtualna metoda przypisania losowych wartoœci do pól obiektu
	virtual void setObject() = 0;

	// setting protected members
	///funkcja ustawiaj¹ca wartoœæ pola protected latitude
	void setLatitude(int);
	///funkcja ustawiaj¹ca wartoœæ pola protected longitude
	void setLongitude(int);
	///funkcja ustawiaj¹ca wartoœæ pola protected hemisphere
	void setHemisphere(std::string);
	///funkcja ustawiaj¹ca wartoœæ pola protected landform
	void setLandform(int);

	// methods
	///metoda zwracaj¹ca losow¹ pó³kulê
	std::string randomHemisphere();

	///destruktor
	~GeographicArea();

protected:
	///zmienna przechowuj¹ca szerokoœæ geograficzn¹ od 0 do 90 stopni
	int latitude;  // szerokosc geograficzna 0 - 90 stopni
	///zmienna przechowuj¹ca d³ugoœæ geograficzn¹ od 0 do 180 stopni
	int longitude;  // dlugosc geograficzna 0 - 180 stopni
	///zmienna przechowuj¹ca pó³kulê: "NE", "NW", "SE", "SW"
	std::string hemisphere;  // NE, NW, SE, SW
	///zmienna przechowuj¹ca wartoœæ powierzchni
	double area;
	///zmienna przechowuj¹ca rzeŸbê terenu
	int landform;
};
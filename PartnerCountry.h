#pragma once

#include <iostream>
#include <string>

///typy granic
enum list_of_borders {EAST, WEST, NORTH, SOUTH};

class PartnerCountry
{
private:
	///zmienna przechowuj�ca typ granicy: EAST, WEST, NORTH, SOUTH
	int border;
	///zmienna przechowuj�ca nazw� kraju partnerskiego
	std::string c_name;
	///zmienna przechowuj�ca ofert� kraju partnerskiego
	std::string deal;

public:
	// constructors
	///konstruktor domy�lny
	PartnerCountry();
	///konstruktor z parametrami przyjmuj�cy typ granicy, nazw� kraju partnerskiego, ofert�
	PartnerCountry(int, std::string, std::string);
	///konstruktor kopiuj�cy
	PartnerCountry(const PartnerCountry &);  // copy constructor

	// getting private members
	///funkcja zwracaj�ca warto�� pola private  border
	int getBorder();
	///funkcja zwracaj�ca warto�� pola private c_name
	std::string getC_Name();
	///funkcja zwracaj�ca warto�� pola private deal
	std::string getDeal();

	// setting private members
	///funkcja ustawiaj�ca warto�� pola private c_name
	void setC_Name(std::string);
	///funkcja ustawiaj�ca warto�� pola private border
	void setBorder(int);
	///funkcja ustawiaj�ca warto�� pola private deal
	void setDeal(std::string);

	// operators
	///operator por�wnania ==
	bool operator==(PartnerCountry &);  // operator ==
	///operator r�no�ci !=
	bool operator!=(PartnerCountry &);  // operator !=
	
	///operator strumienia wyj�cia
	friend std::ostream& operator<< (std::ostream &, PartnerCountry &);  // operator <<
	///operator strumienia wej�cia
	friend std::istream& operator>> (std::istream &, PartnerCountry &);  // operator >>

	// methods
	///metoda wpisuj�ca na ekran stan ca�ego obiektu klasy PartnerCountry
	void showPartner(PartnerCountry &);

	///destruktor
	~PartnerCountry();
};
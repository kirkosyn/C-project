#pragma once

#include <iostream>
#include <string>

///typy granic
enum list_of_borders {EAST, WEST, NORTH, SOUTH};

class PartnerCountry
{
private:
	///zmienna przechowuj¹ca typ granicy: EAST, WEST, NORTH, SOUTH
	int border;
	///zmienna przechowuj¹ca nazwê kraju partnerskiego
	std::string c_name;
	///zmienna przechowuj¹ca ofertê kraju partnerskiego
	std::string deal;

public:
	// constructors
	///konstruktor domyœlny
	PartnerCountry();
	///konstruktor z parametrami przyjmuj¹cy typ granicy, nazwê kraju partnerskiego, ofertê
	PartnerCountry(int, std::string, std::string);
	///konstruktor kopiuj¹cy
	PartnerCountry(const PartnerCountry &);  // copy constructor

	// getting private members
	///funkcja zwracaj¹ca wartoœæ pola private  border
	int getBorder();
	///funkcja zwracaj¹ca wartoœæ pola private c_name
	std::string getC_Name();
	///funkcja zwracaj¹ca wartoœæ pola private deal
	std::string getDeal();

	// setting private members
	///funkcja ustawiaj¹ca wartoœæ pola private c_name
	void setC_Name(std::string);
	///funkcja ustawiaj¹ca wartoœæ pola private border
	void setBorder(int);
	///funkcja ustawiaj¹ca wartoœæ pola private deal
	void setDeal(std::string);

	// operators
	///operator porównania ==
	bool operator==(PartnerCountry &);  // operator ==
	///operator ró¿noœci !=
	bool operator!=(PartnerCountry &);  // operator !=
	
	///operator strumienia wyjœcia
	friend std::ostream& operator<< (std::ostream &, PartnerCountry &);  // operator <<
	///operator strumienia wejœcia
	friend std::istream& operator>> (std::istream &, PartnerCountry &);  // operator >>

	// methods
	///metoda wpisuj¹ca na ekran stan ca³ego obiektu klasy PartnerCountry
	void showPartner(PartnerCountry &);

	///destruktor
	~PartnerCountry();
};
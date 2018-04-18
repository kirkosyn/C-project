#pragma once

#include <iostream>
#include <string>

class Town
{
private:
	///zmienna przechowuj�ca nazw� miasta
	std::string name;
	///zmienna przechowuj�ca liczb� mieszka�c�w
	int number_of_citizens;
	///zmienna przechowuj�ca warto�� powierzchni
	double area;
	///zmienna przechowuj�ca wojew�dztwo
	std::string province;

public:
	// constructors
	///konstruktor domy�lny
	Town();
	///konstruktor z parametrami przyjmuj�cy nazw� miasta, liczb� mieszka�c�w, powierzchni�, wojew�dztwo
	Town(std::string, int, double, std::string);
	///konstruktor kopiuj�cy
	Town(const Town &s);  //copy constructor
	
	// getting private members
	///funkcja zwracaj�ca warto�� pola private name
	std::string getName();
	///funkcja zwracaj�ca warto�� pola private number_of_citizens
	int getNumber_Of_Citizens();
	///funkcja zwracaj�ca warto�� pola private area
	double getArea();
	///funkcja zwracaj�ca warto�� pola private province
	std::string getProvince();

	// setting private members
	///funkcja ustawiaj�ca warto�� pola private name
	void setName(std::string);
	///funkcja ustawiaj�ca warto�� pola private number
	void setNumber(int);
	///funkcja ustawiaj�ca warto�� pola private area
	void setArea(double);
	///funkcja ustawiaj�ca warto�� pola private province
	void setProvince(std::string);

	// operators
	///operator przpypisania =
	Town& operator=(Town &);  // operator =
	///operator dodawania +
	double operator+(Town &);  // operator +
	///operator odejmowania -
	double operator-(Town &);  // operator -
	///operator rzutowania na typ int
	operator int() const;  // cast operator
	
	///operator strumienia wyj�cia
	friend std::ostream& operator<< (std::ostream &, Town &);  // operator <<
	///operator strumienia wej�cia
	friend std::istream& operator>> (std::istream &, Town &);  // operator >>
	
	// methods
	///metoda wpisuj�ca na ekran stan ca�ego obiektu klasy Town
	void showTown(Town &);
	
	///destruktor
	~Town();
};


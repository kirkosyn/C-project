#pragma once

#include <iostream>
#include <string>

class Town
{
private:
	///zmienna przechowuj¹ca nazwê miasta
	std::string name;
	///zmienna przechowuj¹ca liczbê mieszkañców
	int number_of_citizens;
	///zmienna przechowuj¹ca wartoœæ powierzchni
	double area;
	///zmienna przechowuj¹ca województwo
	std::string province;

public:
	// constructors
	///konstruktor domyœlny
	Town();
	///konstruktor z parametrami przyjmuj¹cy nazwê miasta, liczbê mieszkañców, powierzchniê, województwo
	Town(std::string, int, double, std::string);
	///konstruktor kopiuj¹cy
	Town(const Town &s);  //copy constructor
	
	// getting private members
	///funkcja zwracaj¹ca wartoœæ pola private name
	std::string getName();
	///funkcja zwracaj¹ca wartoœæ pola private number_of_citizens
	int getNumber_Of_Citizens();
	///funkcja zwracaj¹ca wartoœæ pola private area
	double getArea();
	///funkcja zwracaj¹ca wartoœæ pola private province
	std::string getProvince();

	// setting private members
	///funkcja ustawiaj¹ca wartoœæ pola private name
	void setName(std::string);
	///funkcja ustawiaj¹ca wartoœæ pola private number
	void setNumber(int);
	///funkcja ustawiaj¹ca wartoœæ pola private area
	void setArea(double);
	///funkcja ustawiaj¹ca wartoœæ pola private province
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
	
	///operator strumienia wyjœcia
	friend std::ostream& operator<< (std::ostream &, Town &);  // operator <<
	///operator strumienia wejœcia
	friend std::istream& operator>> (std::istream &, Town &);  // operator >>
	
	// methods
	///metoda wpisuj¹ca na ekran stan ca³ego obiektu klasy Town
	void showTown(Town &);
	
	///destruktor
	~Town();
};


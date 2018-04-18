#pragma once

#include <string>
#include <iostream>

class Citizen
{
private:
	///zmienna przechowuj�ca imi�
	std::string name;
	///zmienna przechowuj�ca nazwisko
	std::string surname;
	///zmienna przechowuj�ca zaw�d
	std::string job;
	///zmienna przechowuj�ca p�e�
	std::string gender;
	///zmienna przechowuj�ca wiek
	int age;

public:
	// constructors
	///konstruktor domy�lny
	Citizen();
	///konstruktor z parametrami przyjmuj�cy imi�, nazwisko, zaw�d, p�e�, wiek
	Citizen(std::string, std::string, std::string, std::string, int);
	///konstruktor kopiuj�cy
	Citizen(const Citizen &); // copy constructor

	// getting private members
	///funkcja zwracaj�ca warto�� pola private name
	std::string getName();
	///funkcja zwracaj�ca warto�� pola private surname
	std::string getSurname();
	///funkcja zwracaj�ca warto�� pola private age
	int getAge();
	///funkcja zwracaj�ca warto�� pola private job
	std::string getJob();
	///funkcja zwracaj�ca warto�� pola private gender
	std::string getGender();

	// setting private members
	///funkcja ustawiaj�ca warto�� pola private name
	void setName(std::string);
	///funkcja ustawiaj�ca warto�� pola private surname 
	void setSurname(std::string);
	///funkcja ustawiaj�ca warto�� pola private age
	void setAge(int);
	///funkcja ustawiaj�ca warto�� pola private job
	void setJob(std::string);
	///funkcja ustawiaj�ca warto�� pola private gender
	void setGender(std::string);

	// operators
	///operator przypisania =
	Citizen& operator=(Citizen &);  // operator =
	///operator por�wnania >
	bool operator>(Citizen &) const;  // operator >
	///operatorpor�wnania ==
	bool operator==(Citizen &) const;  // operator ==
	
	///operator strumienia wyj�cia
	friend std::ostream& operator<< (std::ostream &, Citizen &);  // operator <<
	///operator strumienia wej�cia
	friend std::istream& operator>> (std::istream &, Citizen &);  // operator >>

	// methods
	///metoda wpisuj�ca na ekran stan ca�ego obiektu klasy Citizen
	void showCitizen(Citizen &);

	///destruktor
	~Citizen();
};


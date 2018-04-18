#pragma once

#include <string>
#include <iostream>

class Citizen
{
private:
	///zmienna przechowuj¹ca imiê
	std::string name;
	///zmienna przechowuj¹ca nazwisko
	std::string surname;
	///zmienna przechowuj¹ca zawód
	std::string job;
	///zmienna przechowuj¹ca p³eæ
	std::string gender;
	///zmienna przechowuj¹ca wiek
	int age;

public:
	// constructors
	///konstruktor domyœlny
	Citizen();
	///konstruktor z parametrami przyjmuj¹cy imiê, nazwisko, zawód, p³eæ, wiek
	Citizen(std::string, std::string, std::string, std::string, int);
	///konstruktor kopiuj¹cy
	Citizen(const Citizen &); // copy constructor

	// getting private members
	///funkcja zwracaj¹ca wartoœæ pola private name
	std::string getName();
	///funkcja zwracaj¹ca wartoœæ pola private surname
	std::string getSurname();
	///funkcja zwracaj¹ca wartoœæ pola private age
	int getAge();
	///funkcja zwracaj¹ca wartoœæ pola private job
	std::string getJob();
	///funkcja zwracaj¹ca wartoœæ pola private gender
	std::string getGender();

	// setting private members
	///funkcja ustawiaj¹ca wartoœæ pola private name
	void setName(std::string);
	///funkcja ustawiaj¹ca wartoœæ pola private surname 
	void setSurname(std::string);
	///funkcja ustawiaj¹ca wartoœæ pola private age
	void setAge(int);
	///funkcja ustawiaj¹ca wartoœæ pola private job
	void setJob(std::string);
	///funkcja ustawiaj¹ca wartoœæ pola private gender
	void setGender(std::string);

	// operators
	///operator przypisania =
	Citizen& operator=(Citizen &);  // operator =
	///operator porównania >
	bool operator>(Citizen &) const;  // operator >
	///operatorporównania ==
	bool operator==(Citizen &) const;  // operator ==
	
	///operator strumienia wyjœcia
	friend std::ostream& operator<< (std::ostream &, Citizen &);  // operator <<
	///operator strumienia wejœcia
	friend std::istream& operator>> (std::istream &, Citizen &);  // operator >>

	// methods
	///metoda wpisuj¹ca na ekran stan ca³ego obiektu klasy Citizen
	void showCitizen(Citizen &);

	///destruktor
	~Citizen();
};


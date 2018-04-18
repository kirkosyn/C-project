#include <iostream>
#include <fstream>
#include <string>
#include "Citizen.h"
#include "Tests.h"

//static Citizen citizen_g = Citizen();

///funkcja testuj¹ca dynamiczne obiekty klasy Citizen
void dynamicTests::citizenTest()
{
	std::cout << "Performing dynamic test of Citizen class:\n";
	std::cout << "..............................\n\n";

	Citizen *citizen_1 = new Citizen();
	Citizen *citizen_2 = new Citizen("Basia", "Kowalska", "Unemployed", "Female", 25);
	Citizen *citizen_3 = new Citizen(*citizen_2);

	std::cout << "Citizen in citizen_3:" << std::endl;
	citizen_3->showCitizen(*citizen_3);

	// checking operators > and == and =
	citizen_3->setAge(40);
	std::cout << "citizen_3 age changed to: " << citizen_3->getAge() << std::endl;
	std::cout << "citizen_2 is younger than citizen_3: " << (*citizen_2 > *citizen_3)
		<< std::endl;
	std::cout << "citizen_1 is the same as citizen_2: " << (*citizen_1 == *citizen_2)
		<< std::endl << std::endl;

	Citizen *citizen_4 = new Citizen();
	*citizen_4 = *citizen_2;

	std::cout << "Citizen in citizen_4:" << std::endl;
	citizen_4->showCitizen(*citizen_4);

	delete citizen_1;
	delete citizen_2;
	delete citizen_3;
	delete citizen_4;


	std::cout << "..............................\n\n";
}

///funkcja dodaj¹ca wiek
void addAge(int added_years)
{
	static Citizen c_l = Citizen("Zosia", "Samosia", "Infant", "Female", 0);
	c_l.setAge(c_l.getAge() + added_years);
	std::cout << "Current age of " << c_l.getName() << " = " << c_l.getAge() << std::endl;
}

///funkcja testuj¹ca statyczne obiekty klasy Citizen
void staticTests::citizenTest()
{
	std::cout << "Performing static test of Citizen class:\n";
	std::cout << "..............................\n\n";

	addAge(1);
	addAge(4);
	addAge(10);

	//citizen_g.setGender("Not defined");
	//std::cout << "Changed gender for global static: " << citizen_g.getGender() << std::endl << std::endl;


	std::cout << "..............................\n\n";
}

///funkcja testuj¹ca automatyczne obiekty klasy Citizen
void automaticTests::citizenTest()
{
	std::cout << "Performing automatic test of Citizen class:\n";
	std::cout << "..............................\n\n";

	Citizen citizen_1 = Citizen();
	Citizen citizen_2 = Citizen("Zbigniew", "Nowak", "Doctor", "Male", 34);
	Citizen citizen_3 = citizen_2;
	Citizen citizen_4 = Citizen(citizen_3);

	// checking operators == and >
	std::cout << "citizen_2 is the same as citizen_3: " << (citizen_2 == citizen_3) << std::endl;
	citizen_3.setSurname("Bak");
	std::cout << "citizen_3 surname changed to: " << citizen_3.getSurname() << std::endl;
	citizen_4.setJob("Vet");
	std::cout << "citizen_4 job changed to: " << citizen_4.getJob() << std::endl;
	std::cout << "citizen_3 is older than citizen_4: " << (citizen_3 > citizen_4)
		<< std::endl << std::endl;


	std::cout << "..............................\n\n";
}
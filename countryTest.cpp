#include <iostream>
#include <fstream>
#include <string>
#include "Country.h"
#include "Tests.h"

//static Country country_g = Country();

///funkcja zapisuj¹ca stan obiektu klasy Country do pliku
void writeToFileTests::countryTest()
{
	std::fstream file;

	file.open("plikcountry.txt", std::ios::out | std::ios::app);
	Country country1("Poland", 991.14, PartnerCountry(100, "China", "Rice"));
	country1.addCitizen(country1, Citizen("Karolina", "Pawluk", "unemployed", "Female", 19));
	country1.addTown(country1, Town("Warsaw", 19831, 99.322, "Mazowsze"));
	country1.setContinent(country1.randomContinent());

	file << country1;

	country1.eraseCitizen();
	country1.eraseTown();

	file.close();
}

///funkcja wczytuj¹ca stan obiektu klasy Country z pliku
void readFromFileTests::countryTest()
{
	std::fstream file;

	file.open("plikcountry.txt", std::ios::in);
	if (!file.good())
	{
		std::cout << "File doesn't exist!\n";
		return;
	}

	Country country1;

	std::vector<Country> vectorcountry;
	std::vector<Country>::iterator it;
	
	while (!file.eof())
	{
		file.seekg(file.tellg());
		file >> country1;
		vectorcountry.push_back(country1);
	}

	unsigned int i = 0;
	for (it = vectorcountry.begin(); i < (vectorcountry.size() - 1); it++, i++)
		(*it).showCountry();

	file.close();
}

///funkcja testuj¹ca dynamiczne obiekty klasy Country
void dynamicTests::countryTest()
{
	std::cout << "Performing dynamic test of Country class:\n";
	std::cout << "..............................\n\n";

	Country *country_1 = new Country();
	PartnerCountry partnerCountry_1 = PartnerCountry(SOUTH, "Spain", "Oranges");
	Citizen citizen_2 = Citizen();
	Town town_3 = Town();
	Country *country_2 = new Country("Poland", 314000.25, partnerCountry_1);
	Country *country_3 = new Country(*country_2);

	// adding citizens
	std::cout << " Current amount of countries: " << country_1->getAmountOfCountries() << std::endl;
	country_2->addCitizen(*country_2, citizen_2);
	country_2->addCitizen(*country_2, Citizen("Zbigniew", "Boniek", "Soccer Player", "Male", 47));
	country_2->addCitizen(*country_2, Citizen("Malgorzata","Kowalska","Gardener","Female",19));
	country_2->addCitizen(*country_2, Citizen(citizen_2));

	std::cout << "Current amount of citizens in country_2: " << country_2->getAmountOfCitizens() 
		<< std::endl;
	std::cout << "List of citizens in country_2 after adding:" << std::endl;
	(*country_2)[0];
	std::cout << "\n\n";
	
	// erasing citizens
	country_2->eraseCitizen();
	std::cout << "List of citizens in country_2 after erasing:" << std::endl;
	(*country_2)[0];
	country_2->eraseCitizen();
	country_2->eraseCitizen();
	country_2->eraseCitizen();
	std::cout << "\n\n";

	// adding towns
	country_3->addTown(*country_3, town_3);
	country_3->addTown(*country_3, Town("Zakopane", 10, 951.251, "Malopolska"));
	country_3->addTown(*country_3, Town("Gdansk", 55, 125.00, "Pomorskie"));

	std::cout << "Current amount of towns in country_3: " << country_3->getAmountOfTowns() 
		<< std::endl;
	std::cout << "List of towns in country_3 after adding:" << std::endl;
	(*country_3)[1];
	std::cout << "\n\n";

	// erasing towns
	country_2->eraseTown();
	std::cout << "List of towns in country_3 after erasing:" << std::endl;
	(*country_3)[1];
	country_2->eraseTown();
	country_2->eraseTown();
	std::cout << "\n\n";

	// adding partner
	country_1->setPartner(PartnerCountry(NORTH, "Sweden", "Fish"));
	country_2->setPartner(PartnerCountry());
	std::cout << "Partner for country_1:" << std::endl;
	(*country_1)[2];
	std::cout << "\n\n";

	// checking operators == and >
	std::cout << "country_1 has the same partner country as country_2: " << (*country_1 == *country_2)
		<< std::endl;
	std::cout << "country_2 is bigger than country_3: " << (*country_2 > *country_3) 
		<< std::endl;

	delete country_1;
	delete country_2;
	delete country_3;


	std::cout << "..............................\n\n";
}

///funkcja dodaj¹ca powierzchniê
void addArea(double a)
{
	static Country country_l = Country();
	country_l.setArea(country_l.getArea() + a);
	std::cout << "Current area of " << country_l.getName() << " = " << country_l.getArea() << "\n";
}

///funkcja testuj¹ca statyczne obiekty klasy Country
void staticTests::countryTest()
{
	std::cout << "Performing static test of Country class:\n";
	std::cout << "..............................\n\n";

	addArea(52.22);
	addArea(88891.999);
	addArea(-14141.111);

	//country_g.setName("Brazil");
	//std::cout << "Changed name for global static: " << country_g.getName() << "\n\n";


	std::cout << "..............................\n\n";
}

///funkcja testuj¹ca automatyczne obiekty klasy Country
void automaticTests::countryTest()
{
	//std::cout << "Performing automatic test of Country class:\n";
	//std::cout << "..............................\n\n";

	Country country_1 = Country();
	PartnerCountry partnerCountry_1 = PartnerCountry(EAST, "USA", "Hardware");
	Citizen citizen_2 = Citizen();
	Town town_3 = Town();
	Country country_2 = Country("China", 38591850.555, partnerCountry_1);
	Country country_3 = Country(country_2);

	// adding citizens
	std::cout << " Current amount of countries: " << country_1.getAmountOfCountries() << "\n\n";
	
	country_2.addCitizen(country_2, citizen_2);
	country_2.addCitizen(country_2, Citizen("Marianna", "Nowak", "Politician", "Female", 34));
	country_2.addCitizen(country_2, Citizen("Henryk", "Abakus", "Policeman", "Male", 44));
	country_2.addCitizen(country_2, Citizen(citizen_2));

	std::cout << "Current amount of citizens in country_2: " << country_2.getAmountOfCitizens()
		<< "\n\n";
	std::cout << "List of citizens in country_2 after adding:" << std::endl;
	(country_2)[0];
	std::cout << "\n\n";

	// erasing citizens
	country_2.eraseCitizen();
	std::cout << "List of citizens in country_2 after erasing:" << std::endl;
	(country_2)[0];
	country_2.eraseCitizen();
	country_2.eraseCitizen();
	country_2.eraseCitizen();
	std::cout << "\n\n";

	// adding towns
	country_3.addTown(country_3, town_3);
	country_3.addTown(country_3, Town("Szczecin", 91481, 9551.2, "Zachodniopomorskie"));
	country_3.addTown(country_3, Town("Wroclaw", 5125, 155.00, "Wielkopolskie"));
	
	std::cout << "List of towns in country_3 after adding:" << std::endl;
	(country_3)[1];
	std::cout << "\n\n";
	
	// erasing towns
	country_3.eraseTown();

	std::cout << "Current amount of towns in country_3: " << country_3.getAmountOfTowns()
		<< "\n\n";
	std::cout << "List of towns in country_3 after erasing:" << std::endl;
	(country_3)[1];
	country_3.eraseTown();
	country_3.eraseTown();
	std::cout << "\n\n";
	
	// adding partner
	PartnerCountry partner_3 = PartnerCountry(EAST, "Japan", "Seaweed");
	country_1.setPartner(partner_3);
	country_2.setPartner(PartnerCountry(partner_3));
	std::cout << "Partner for country_3:" << std::endl;
	(country_1)[2];
	std::cout << "\n\n";

	// checking operators == and >
	std::cout << "country_1 has the same partner country as country_2: " << (country_1 == country_2)
		<< "\n";
	std::cout << "country_2 is bigger than country_3: " << (country_2 > country_3)
		<< "\n\n";


	std::cout << "..............................\n\n";
}
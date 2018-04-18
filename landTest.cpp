#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GeographicArea.h"
#include "WaterArea.h"
#include "LandArea.h"
#include "Country.h"
#include "Tests.h"

///funkcja zapisuj¹ca stan obiektu klasy WaterArea do pliku
void writeToFileTests::waterAreaTest()
{
	std::fstream file;
	file.open("plikwater.txt", std::ios::out | std::ios::app);

	WaterArea sea;
	sea.setObject();
	file << sea;

	file.close();
}

///funkcja zapisuj¹ca stan obiektu klasy LandArea do pliku
void writeToFileTests::landAreaTest()
{
	std::fstream file;
	file.open("plikland.txt", std::ios::out | std::ios::app);

	LandArea land;
	land.setObject();
	file << land;

	file.close();
}

///funkcja wczytuj¹ca stan obiektu klasy WaterArea z pliku
void readFromFileTests::waterAreaTest()
{
	std::fstream file;

	file.open("plikwater.txt", std::ios::in);
	if (!file.good())
	{
		std::cout << "File doesn't exist!\n";
		return;
	}

	WaterArea sea;
	std::vector<WaterArea> vectorsea;
	std::vector<WaterArea>::iterator it;

	while (!file.eof())
	{
		file.seekg(file.tellg());
		file >> sea;
		vectorsea.push_back(sea);
	}

	unsigned int i = 0;
	for (it = vectorsea.begin(); i < (vectorsea.size() - 1); it++, i++)
		(*it).showArea();

	file.close();
}

///funkcja wczytuj¹ca stan obiektu klasy LandArea z pliku
void readFromFileTests::landAreaTest()
{
	std::fstream file;

	file.open("plikland.txt", std::ios::in);
	if (!file.good())
	{
		std::cout << "File doesn't exist!\n";
		return;
	}

	LandArea land;
	std::vector<LandArea> vectorland;
	std::vector<LandArea>::iterator it;

	while (!file.eof())
	{
		file.seekg(file.tellg());
		file >> land;
		vectorland.push_back(land);
	}

	unsigned int i = 0;
	for (it = vectorland.begin(); i < (vectorland.size() - 1); it++, i++)
		(*it).showArea();

	file.close();
}

///funkcja testuj¹ca automatyczne obiekty klasy WaterArea
void automaticTests::waterAreaTest()
{
	WaterArea reservoir;
	reservoir.showArea();

	// setting object
	reservoir.setTypeOfWater("Sweet_water");
	reservoir.assignArea(991.14, 11.55);
	reservoir.setHemisphere("NW");
	reservoir.setLatitude(89);
	reservoir.setLongitude(11);
	std::cout << "reservoir latitude: " << reservoir.getLatitude() << std::endl;
	std::cout << "reservoir longitude: " << reservoir.getLongitude() << std::endl << std::endl;
	reservoir.setLandform(BAY);
	reservoir.setLatitude(23);
	reservoir.setLongitude(122);

	reservoir.showArea();

	// setting random values
	reservoir.setObject();
	reservoir.showArea();

}

///funkcja testuj¹ca automatyczne obiekty klasy LandArea
void automaticTests::landAreaTest()
{
	LandArea land;
	land.showArea();

	// setting object
	land.assignArea(200.13, 66.3);
	land.setHemisphere("NE");
	land.setLandform(TUNDRA);
	land.setLatitude(55);
	land.setLongitude(99);
	std::cout << "land latitude: " << land.getLatitude() << std::endl;
	std::cout << "land longitude: " << land.getLongitude() << std::endl << std::endl;
	land.setContinent("Asia");
	land.setBorders(9191);
	land.setLatitude(3);
	land.setLongitude(150);

	land.showArea();

	// setting random values
	land.setObject();
	land.showArea();
}

///funkcja testuj¹ca obiekty klas WaterArea, LandArea, GeographicArea, Country
void automaticTests::allClassesTest()
{
	GeographicArea *areas[3];
	LandArea land;
	WaterArea reservoir;
	Country country;

	areas[0] = &land;
	areas[1] = &reservoir;
	areas[2] = &country;

	for (int i = 0; i < 3; i++)
	{
		areas[i]->assignArea(911.1, 41.55);
		areas[i]->setHemisphere("SW");
		areas[i]->setLatitude(41);
		areas[i]->setLongitude(111);
		areas[i]->showArea();
	}
	
	std::cout << "\n****\n";
	
	for (int i = 0; i < 3; i++)
	{
		areas[i]->setObject();
		areas[i]->showArea();
	}

	std::vector<Country> countries;
	std::vector<LandArea> lands;
	std::vector<WaterArea> reservoirs;
	std::vector<Country>::iterator itc;
	std::vector<LandArea>::iterator itl;
	std::vector<WaterArea>::iterator itr;

	countries.push_back(Country());
	countries.push_back(Country("Norway", 138.14, PartnerCountry()));
	countries.push_back(Country("Sweden", 4434.55, PartnerCountry(516,"Denmark", "Pears")));

	lands.push_back(LandArea());
	lands.push_back(land);

	reservoirs.push_back(WaterArea());
	reservoirs.push_back(reservoir);

	std::cout << "\n****";
	std::cout << "\nCountry vector\n\n";
	for (itc = countries.begin(); itc != countries.end(); itc++)
	{
		(*itc).setObject();
		(*itc).showCountry();
		(*itc).showArea();
	}

	std::cout << "\n****";
	std::cout << "\nLandArea vector\n\n";
	for (itl = lands.begin(); itl != lands.end(); itl++)
		(*itl).showArea();

	std::cout << "\n****";
	std::cout << "\nWaterArea vector\n\n";
	for (itr = reservoirs.begin(); itr != reservoirs.end(); itr++)
		(*itr).showArea();

}
#include <iostream>
#include <fstream>
#include <string>
#include "Town.h"
#include "Tests.h"

//static Town town_g = Town();

///funkcja testuj¹ca dynamiczne obiekty klasy Town
void dynamicTests::townTest()
{
	std::cout << "Performing dynamic test of Town class:\n";
	std::cout << "..............................\n\n";

	Town *town_1 = new Town();
	Town *town_2 = new Town("Cracow", 20000, 50.9919, "Malopolska");
	Town *town_3 = new Town(*town_2);

	std::cout << "Town in town_3:" << std::endl;
	town_3->showTown(*town_3);

	// checking operators + and - and (int)
	town_3->setArea(255.5252);
	std::cout << "town_3 area changed to: " << town_3->getArea() << std::endl;

	std::cout << "The sum of areas of town_1 and town_2 is: " << (*town_1 + *town_2)
		<< std::endl;

	std::cout << "town_3 area casted to int: " << (int)(*town_3) << std::endl;

	std::cout << "The difference between areas of town_3 and town_1 is: " << (*town_3 - *town_1)
		<< std::endl << std::endl;

	Town *town_4 = new Town();
	*town_4 = *town_1;

	std::cout << "Town in town_4:" << std::endl;
	town_4->showTown(*town_4);

	delete town_1;
	delete town_2;
	delete town_3;
	delete town_4;


	std::cout << "..............................\n\n";
}

///funkcja dodaj¹ca powierzchniê
void addAreas(double added_area)
{
	static Town t_l = Town();
	t_l.setArea(t_l.getArea() + added_area);
	std::cout << "Current area of " << t_l.getName() << " = " << t_l.getArea() << std::endl;
}

///funkcja testuj¹ca statyczne obiekty klasy Town
void staticTests::townTest()
{
	std::cout << "Performing static test of Town class:\n";
	std::cout << "..............................\n\n";

	addAreas(1000.52);
	addAreas(-399.622);
	addAreas(9999.888);

	//town_g.setName("Katowice");
	//std::cout << "Changed name for global static: " << town_g.getName() << std::endl << std::endl;


	std::cout << "..............................\n\n";
}

///funkcja testuj¹ca automatyczne obiekty klasy Town
void automaticTests::townTest()
{
	std::cout << "Performing automatic test of Town class:\n";
	std::cout << "..............................\n\n";

	Town town_1 = Town();
	Town town_2 = Town("Lublin", 40000, 999.838, "Lubelszczyzna");
	Town town_3 = town_2;
	Town town_4 = Town(town_3);

	std::cout << "Town in town_4:" << std::endl;
	town_4.showTown(town_4);

	// checking operators + and -
	town_3.setProvince("Slask");
	std::cout << "town_3 province changed to: " << town_3.getProvince() << std::endl;
	town_2.setNumber(1);
	std::cout << "town_1 number of citizens changed to: " << town_1.getNumber_Of_Citizens() << std::endl;
	
	std::cout << "The sum of areas of town_2 and town_3 is: " << (town_2 + town_3)
		<< std::endl;
	
	std::cout << "The difference between areas of town_4 and town_1 is: " << (town_4 - town_1)
		<< std::endl << std::endl;


	std::cout << "..............................\n\n";
	
}
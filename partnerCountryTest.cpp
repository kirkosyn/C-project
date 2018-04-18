#include <iostream>
#include <fstream>
#include <string>
#include "PartnerCountry.h"
#include "Tests.h"

//static PartnerCountry partner_g = PartnerCountry();

///funkcja testuj¹ca dynamiczne obiekty klasy PartnerCountry
void dynamicTests::partnerCountryTest()
{
	std::cout << "Performing dynamic test of PartnerCountry class:\n";
	std::cout << "..............................\n\n";

	PartnerCountry *partner_1 = new PartnerCountry();
	PartnerCountry *partner_2 = new PartnerCountry(NORTH, "Russia", "Fuel");
	PartnerCountry *partner_3 = new PartnerCountry(*partner_2);
	
	std::cout << "Partner in partner_3:" << std::endl;
	partner_3->showPartner(*partner_3);

	// checking operators == and << and !=
	partner_3->setC_Name("Denmark");
	std::cout << "partner_3 country name changed to: " << partner_3->getC_Name() << std::endl;
	std::cout << "partner_2 has the same name as partner_3: " << (*partner_2 == *partner_3)
		<< std::endl;
	
	std::cout << "Using operator<<" << std::endl;
	std::cout << *partner_1 << std::endl;

	partner_2->setDeal("Potatoes");
	std::cout << "partner_2 deal changed to: " << partner_2->getDeal() << std::endl;
	std::cout << "partner_2 is different from partner_1: " << (*partner_2 != *partner_1) 
		<< std::endl;

	delete partner_1;
	delete partner_2;
	delete partner_3;


	std::cout << "..............................\n\n";
}

///funkcja zmieniaj¹ca typ granicy
void changeBorder()
{
	static PartnerCountry c_l = PartnerCountry(EAST, "Germany", "Apples");
	c_l.setBorder(c_l.getBorder() + 1);
	std::cout << "Current border of " << c_l.getC_Name() << " = ";
	switch (c_l.getBorder())
	{
	case EAST:
		std::cout << "East";
		break;
	case WEST:
		std::cout << "West";
		break;
	case NORTH:
		std::cout << "North";
		break;
	case SOUTH:
		std::cout << "South";
		break;
	}
	std::cout << std::endl;
}

///funkcja testuj¹ca statyczne obiekty klasy PartnerCountry
void staticTests::partnerCountryTest()
{
	std::cout << "Performing static test of PartnerCountry class:\n";
	std::cout << "..............................\n\n";

	changeBorder();
	changeBorder();
	changeBorder();

	//partner_g.setDeal("Not defined");
	//std::cout << "Changed deal for global static: " << partner_g.getDeal() << std::endl;


	std::cout << "..............................\n\n";
}

///funkcja testuj¹ca automatyczne obiekty klasy PartnerCountry
void automaticTests::partnerCountryTest()
{
	std::cout << "Performing automatic test of PartnerCountry class:\n";
	std::cout << "..............................\n\n";

	PartnerCountry partner_1 = PartnerCountry();
	PartnerCountry partner_2 = PartnerCountry(SOUTH, "Croatia", "Flowers");
	PartnerCountry partner_3 = partner_2;
	PartnerCountry partner_4 = PartnerCountry(partner_3);

	std::cout << "Partner in partner_2:" << std::endl;
	partner_2.showPartner(partner_2);

	// checking operators == and << and !=
	std::cout << "partner_2 is the same as partner_3: " << (partner_2 == partner_3) << std::endl;
	
	partner_4.setBorder(WEST);
	std::cout << "partner_4 border changed to: " << partner_4.getBorder() << std::endl;
	std::cout << "Using operator<<" << std::endl;
	std::cout << partner_1 << std::endl;
	
	partner_1.setDeal("Wood");
	std::cout << "partner_1 deal changed to: " << partner_1.getDeal() << std::endl;
	std::cout << "partner_2 is different from partner_1: " << (partner_2 != partner_1)
		<< std::endl << std::endl;


	std::cout << "..............................\n\n";
}
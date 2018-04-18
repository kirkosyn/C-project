#include "PartnerCountry.h"



PartnerCountry::PartnerCountry()
{	
	#ifdef _DEBUG
		std::cout << "PartnerCountry class default constructor fired.\n";
	#endif // _DEBUG
	
	border = WEST;
	c_name = "Germany";
	deal = "Apples";
}

PartnerCountry::PartnerCountry(int b, std::string c, std::string ca)
{
	#ifdef _DEBUG
		std::cout << "PartnerCountry class constructor with parameters fired.\n";
	#endif // _DEBUG

	border = b;
	c_name = c;
	deal = ca;
}

PartnerCountry::PartnerCountry(const PartnerCountry & s)
{
	#ifdef _DEBUG
		std::cout << "PartnerCountry class copy constructor fired.\n";
	#endif // _DEBUG

	border = s.border;
	c_name = s.c_name;
	deal = s.deal;
}

int PartnerCountry::getBorder()
{
	return border;
}

std::string PartnerCountry::getC_Name()
{
	return c_name;
}

std::string PartnerCountry::getDeal()
{
	return deal;
}

void PartnerCountry::setC_Name(std::string c)
{
	c_name = c;
}

void PartnerCountry::setBorder(int b)
{
	border = b;
}

void PartnerCountry::setDeal(std::string c)
{
	deal = c;
}

bool PartnerCountry::operator==(PartnerCountry & p)
{
	return p.c_name == c_name;
}

bool PartnerCountry::operator!=(PartnerCountry & p)
{
	return p.deal != deal;
}

void PartnerCountry::showPartner(PartnerCountry & t)
{
	std::cout << "Border : ";
	switch (t.border)
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
	std::cout << "Name : " << t.c_name << std::endl;
	std::cout << "Deal : " << t.deal << std::endl;
}

std::ostream & operator<<(std::ostream & s, PartnerCountry & n)
{
	s << n.c_name << std::endl;
	s << n.border << std::endl;
	s << n.deal << std::endl;

	return s;
}

std::istream & operator>>(std::istream &s , PartnerCountry & n)
{
	s >> n.c_name;
	s >> n.border;
	s >> n.deal;

	return s;
}

PartnerCountry::~PartnerCountry()
{
	#ifdef _DEBUG
		std::cout << "PartnerCountry class destructor fired.\n";
	#endif // _DEBUG
}



#include "Town.h"

Town::Town()
{
	#ifdef _DEBUG
		std::cout << "Town class default constructor fired.\n";
	#endif // _DEBUG

	name = "Warsaw";
	number_of_citizens = 200000;
	area = 5500.540;
	province = "Mazowsze";
}

Town::Town(std::string na, int n, double a, std::string p)
{
	#ifdef _DEBUG
		std::cout << "Town class constructor with parameters fired.\n";
	#endif // _DEBUG
	
	name = na;
	number_of_citizens = n;
	area = a;
	province = p;
}

Town::Town(const Town & s)
{
	#ifdef _DEBUG
		std::cout << "Town class copy constructor fired.\n";
	#endif // _DEBUG

	name = s.name;
	number_of_citizens = s.number_of_citizens;
	area = s.area;
	province = s.province;
}

std::string Town::getName()
{
	return name;
}

int Town::getNumber_Of_Citizens()
{
	return number_of_citizens;
}

double Town::getArea()
{
	return area;
}

std::string Town::getProvince()
{
	return province;
}


void Town::setName(std::string n)
{
	name = n;
}

void Town::setNumber(int n)
{
	number_of_citizens = n;
}

void Town::setArea(double a)
{
	area = a;
}

void Town::setProvince(std::string p)
{
	province = p;
}

Town & Town::operator=(Town & p)
{
	name = p.name;
	number_of_citizens = p.number_of_citizens;
	area = p.area;
	province = p.province;
	return *this;
}

double Town::operator+(Town & t)
{
	double sumOfAreas = 0;
	sumOfAreas = t.area + area;
	return sumOfAreas;
}

double Town::operator-(Town & t)
{
	double subOfAreas = 0;
	subOfAreas = t.area - area;
	return subOfAreas;
}

Town::operator int() const
{
	int temp;
	temp = (int) area;
	return temp;
}

void Town::showTown(Town & t)
{
	std::cout << "Name of the town : " << t.name << std::endl;
	std::cout << "Area : " << t.area << std::endl;
	std::cout << "Number of citizens : " << t.number_of_citizens << std::endl;
	std::cout << "Province : " << t.province << "\n\n";
}

Town::~Town()
{
	#ifdef _DEBUG
		std::cout << "Town class destructor fired.\n";
	#endif // _DEBUG
}

std::ostream & operator<<(std::ostream & s, Town & t)
{
	s << t.area << std::endl;
	s << t.name << std::endl;
	s << t.number_of_citizens << std::endl;
	s << t.province << std::endl;

	return s;
}

std::istream & operator>>(std::istream & s, Town & t)
{
	s >> t.area;
	s >> t.name;
	s >> t.number_of_citizens;
	s >> t.province;

	return s;
}

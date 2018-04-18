#include "WaterArea.h"

WaterArea::WaterArea()
{
#ifdef _DEBUG
	std::cout << "WaterArea class default constructor fired.\n";
#endif // _DEBUG
	typeOfWater = "Salt_water";
	landform = 4;
	area = 5252.252;
	latitude = 25;
	longitude = 55;
	hemisphere = "SW";
}

WaterArea::~WaterArea()
{
#ifdef _DEBUG
	std::cout << "WaterArea class destructor fired.\n";
#endif // _DEBUG
}

std::string WaterArea::getTypeOfWater()
{
	return typeOfWater;
}

int WaterArea::getLatitude()
{
	return latitude;
}

int WaterArea::getLongitude()
{
	return longitude;
}

std::string WaterArea::getHemisphere()
{
	return hemisphere;
}

void WaterArea::setTypeOfWater(std::string s)
{
	typeOfWater = s;
}

void WaterArea::setObject()
{
	srand((unsigned int)time(NULL));
	double area = static_cast <double> (rand()) / (static_cast <double> (1000));
	int latitude = rand() % 91;
	int longitude = rand() % 181;
	int landform = rand() % 5;

	setLatitude(latitude);
	setLongitude(longitude);
	setLandform(landform);
	assignArea(area, area + 1);
	setHemisphere(randomHemisphere());
	setTypeOfWater(randomType());
}

void WaterArea::assignArea(double a, double b)
{
	area = 3.14 * a * b;
}

void WaterArea::whoLives()
{
	std::cout << "Here live only fish\n\n";
}

void WaterArea::showArea()
{
	std::cout << typeOfWater << std::endl;
	std::cout << area << std::endl;
	std::cout << latitude << std::endl;
	std::cout << longitude << std::endl;
	std::cout << hemisphere << std::endl;
	std::cout << whichLandform(landform) << std::endl;
	whoLives();
}

std::string WaterArea::whichLandform(int i)
{
	switch (i)
	{
	case 0:
		return "Bay";
	case 1:
		return "Coast";
	case 2:
		return "Lagoon";
	case 3:
		return "Channel";
	case 4:
		return "Oceanic_trench";
	default:
		return "undefined";
	}
}

std::string WaterArea::randomType()
{
	srand((unsigned int)time(NULL));
	int type = rand() % 2;

	switch (type)
	{
	case 0:
		return "Salt_water";
	case 1:
		return "Sweet_water";
	default:
		return "undefined";
	}
}

std::ostream & operator<<(std::ostream & s, WaterArea & w)
{
	s << w.typeOfWater << std::endl;
	s << w.area << std::endl;
	s << w.latitude << std::endl;
	s << w.longitude << std::endl;
	s << w.hemisphere << std::endl;
	s << w.landform << std::endl;

	return s;
}

std::istream & operator>>(std::istream & s, WaterArea & w)
{
	s >> w.typeOfWater;
	s >> w.area;
	s >> w.latitude;
	s >> w.longitude;
	s >> w.hemisphere;
	s >> w.landform;

	return s;
}

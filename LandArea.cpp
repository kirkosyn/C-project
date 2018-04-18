#include "LandArea.h"

bool LandArea::suitable_for_cultivation()
{
	if ((int)area % 2 == 1)
	{
		suitable = 0;
		return false;
	}
	else
	{
		suitable = 1;
		return true;
	}
}

LandArea::LandArea()
{
#ifdef _DEBUG
	std::cout << "LandArea class default constructor fired.\n";
#endif // _DEBUG
	landform = 0;
	area = 952.292;
	latitude = 75;
	longitude = 10;
	hemisphere = "NE";
	borders = 0.889;
	continent = "North_America";
}

LandArea::~LandArea()
{
#ifdef _DEBUG
	std::cout << "LandArea class destructor fired.\n";
#endif // _DEBUG
}

double LandArea::getArea()
{
	return area;
}

int LandArea::getLatitude()
{
	return latitude;
}

int LandArea::getLongitude()
{
	return longitude;
}

std::string LandArea::getHemisphere()
{
	return hemisphere;
}

void LandArea::setContinent(std::string s)
{
	continent = s;
}

void LandArea::setBorders(double b)
{
	borders = b;
}

void LandArea::setObject()
{
	srand((unsigned int)time(NULL));
	double area = static_cast <double> (rand()) / (static_cast <double> (1000));
	double borders = static_cast <double> (rand()) / (static_cast <double> (1000));
	int latitude = rand() % 91;
	int longitude = rand() % 181;
	int landform = rand() % 7;

	setLatitude(latitude);
	setLongitude(longitude);
	setLandform(landform);
	assignArea(area, area + 1);
	setHemisphere(randomHemisphere());
	setBorders(borders);
	setContinent(randomContinent());
	suitable_for_cultivation();
}

void LandArea::assignArea(double a, double b)
{
	area = a * b;
}

void LandArea::whoLives()
{
	std::cout << "Here live different animals\n";
	if (suitable == 0)
		std::cout << "This area is not good for cultivating\n\n";
	else
		std::cout << "This area is good for cultivating\n\n";
}

void LandArea::showArea()
{
	std::cout << continent << std::endl;
	std::cout << area << std::endl;
	std::cout << borders << std::endl;
	std::cout << latitude << std::endl;
	std::cout << longitude << std::endl;
	std::cout << hemisphere << std::endl;
	std::cout << whichLandform(landform) << std::endl;
	whoLives();
}

std::string LandArea::whichLandform(int i)
{
	switch (i)
	{
	case 0:
		return "Mountain";
	case 1:
		return "Valley";
	case 2:
		return "Tundra";
	case 3:
		return "Cave";
	case 4:
		return "Desert";
	case 5:
		return "Island";
	case 6:
		return "Plain";
	default:
		return "undefined";
	}
}

std::string LandArea::randomContinent()
{
	srand((unsigned int)time(NULL));
	switch (rand() % 7)
	{
	case 0:
		return "Australia";
	case 1:
		return "Europe";
	case 2:
		return "North_America";
	case 3:
		return "South_America";
	case 4:
		return "Asia";
	case 5:
		return "Africa";
	case 6:
		return "Antarctica";
	default:
		return "undefined";
	}
}

std::ostream & operator<<(std::ostream & s, LandArea & l)
{
	s << l.continent << std::endl;
	s << l.area << std::endl;
	s << l.borders << std::endl;
	s << l.latitude << std::endl;
	s << l.longitude << std::endl;
	s << l.hemisphere << std::endl;
	s << l.landform << std::endl;
	s << l.suitable << std::endl;

	return s;
}

std::istream & operator>>(std::istream & s, LandArea & l)
{
	s >> l.continent;
	s >> l.area;
	s >> l.borders;
	s >> l.latitude;
	s >> l.longitude;
	s >> l.hemisphere;
	s >> l.landform;
	s >> l.suitable;
	return s;
}

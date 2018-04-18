#include "GeographicArea.h"

GeographicArea::GeographicArea()
{
#ifdef _DEBUG
	std::cout << "GeographicArea class default constructor fired.\n";
#endif // _DEBUG
}

void GeographicArea::setLandform(int i)
{
	landform = i;
}

void GeographicArea::setLatitude(int number)
{
	latitude = number;
}

void GeographicArea::setLongitude(int number)
{
	longitude = number;
}

void GeographicArea::setHemisphere(std::string h)
{
	hemisphere = h;
}

std::string GeographicArea::randomHemisphere()
{
	srand((unsigned int)time(NULL));
	switch (rand() % 4)
	{
	case 0:
		return "NW";
	case 1:
		return "SW";
	case 2:
		return "SE";
	case 3:
		return "NE";
	default:
		return "undefined";
	}
}

GeographicArea::~GeographicArea()
{
#ifdef _DEBUG
	std::cout << "GeographicArea class destructor fired.\n";
#endif // _DEBUG
}


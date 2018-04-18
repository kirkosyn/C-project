#include "Country.h"

int Country::amount_of_countries = 0;
int Country::amount_of_citizens = 0;
int Country::amount_of_towns = 0;

Country::Country()
{
	#ifdef _DEBUG
		std::cout << "Country class default constructor fired.\n";
	#endif // _DEBUG

	name = "Poland";
	area = 314643.6323;
	partner = PartnerCountry();

	//citizenArray = new Citizen[MAX_AMOUNT_OF_CITIZENS];
	//townArray = new Town[MAX_AMOUNT_OF_TOWNS];

	//citizenArray.push_back(Citizen());
	//townArray.push_back(Town());

	amount_of_countries++;
}

Country::Country(std::string n, double a, PartnerCountry & ne)
{
	#ifdef _DEBUG
		std::cout << "Country class constructor with parameters fired.\n";
	#endif // _DEBUG

	name = n;
	area = a;
	partner = ne;

	//citizenArray = new Citizen[MAX_AMOUNT_OF_CITIZENS];
	//townArray = new Town[MAX_AMOUNT_OF_TOWNS];

	//citizenArray.push_back(Citizen());
	//townArray.push_back(Town());

	amount_of_countries++;
}

Country::Country(const Country &s)
{
	#ifdef _DEBUG
		std::cout << "Country class copy constructor fired.\n";
	#endif // _DEBUG

	name = s.name;
	area = s.area;
	partner = s.partner;

	std::vector<Citizen>::const_iterator citizenit;
	std::vector<Town>::const_iterator townit;
	
	for (citizenit = s.citizenArray.begin(); citizenit != s.citizenArray.end(); citizenit++)
		citizenArray.push_back(*citizenit);
	for (townit = s.townArray.begin(); townit != s.townArray.end(); townit++)
		townArray.push_back(*townit);

	//citizenArray = new Citizen[MAX_AMOUNT_OF_CITIZENS];
	//townArray = new Town[MAX_AMOUNT_OF_TOWNS];

	/*for (int i = 0; i < s.amount_of_countries; i++)
	citizenArray[i] = s.citizenArray[i];
	for (int i = 0; i < s.amount_of_countries; i++)
	townArray[i] = s.townArray[i];*/
	amount_of_countries++;
}

std::string Country::getName()
{
	return name;
}

/*double Country::getArea()
{
	return area;
}

Citizen * Country::getCitizen() const
{
	return citizenArray;
}

Town * Country::getTown() const
{
	return townArray;
}*/

PartnerCountry Country::getPartner() const
{
	return partner;
}

int Country::getAmountOfCountries()
{
	return amount_of_countries;
}

int Country::getAmountOfCitizens()
{
	return amount_of_citizens;
}

int Country::getAmountOfTowns()
{
	return amount_of_towns;
}

void Country::setPartner(PartnerCountry & n)
{
	partner = n;
}

void Country::setName(std::string n)
{
	name = n;
}

void Country::setArea(double a)
{
	area = a;
}

void Country::assignArea(double a, double b)
{
	area += a * b;
}

void Country::whoLives()
{
	std::cout << "Here live only people\n\n";
}

void Country::showCountry()
{
	std::cout << name << std::endl;
	std::cout << partner << std::endl;
	/*std::vector<Citizen>::iterator citizenit;
	std::vector<Town>::iterator townit;
	for (citizenit = citizenArray.begin(); citizenit != citizenArray.end(); citizenit++)
		std::cout << *citizenit << std::endl;
	for (townit = townArray.begin(); townit != townArray.end(); townit++)
		std::cout << *townit << std::endl;*/
}

Country Country::addCitizen(Country & c, Citizen & citizen)
{
	if (c.amount_of_citizens >= MAX_AMOUNT_OF_CITIZENS)
		std::cout << "There are too many citizens\n";
	else {
		//c.citizenArray[c.amount_of_citizens] = citizen;
		c.citizenArray.push_back(citizen);
		c.amount_of_citizens++;
	}
	return c;
}

Country Country::addTown(Country & c, Town & town)
{
	if (c.amount_of_towns >= MAX_AMOUNT_OF_TOWNS)
		std::cout << "There are too many towns\n";
	else {
		//c.townArray[c.amount_of_towns] = town;
		c.townArray.push_back(town);
		c.amount_of_towns++;
	}
	return c;
}

Country Country::eraseCitizen()
{
	//Country temp;
	
	if (citizenArray.empty())
		std::cout << "There are not enough citizens in country\n";
	else 
	{
		/*amount_of_citizens--;
		for (int i = 0; i < amount_of_citizens; i++)
			temp.citizenArray[i] = citizenArray[i];
		delete[] citizenArray;
		citizenArray = new Citizen[MAX_AMOUNT_OF_CITIZENS];
		for (int i = 0; i < amount_of_citizens; i++)
			citizenArray[i] = temp.citizenArray[i];*/

		citizenArray.pop_back();
		amount_of_citizens--;
	}

	return *this;
}

Country Country::eraseTown()
{
	//Country temp;

	if (townArray.empty())
		std::cout << "There are not enough towns in country\n";
	else
	{
		/*amount_of_towns--;
		for (int i = 0; i < amount_of_towns; i++)
			temp.townArray[i] = townArray[i];
		delete[] townArray;
		townArray = new Town[MAX_AMOUNT_OF_TOWNS];
		for (int i = 0; i < amount_of_towns; i++)
			townArray[i] = temp.townArray[i];*/

		townArray.pop_back();
		amount_of_towns--;
	}

	return *this;
}

bool Country::operator>(Country & a) const
{
	if (area > a.area)
		return true;
	else
		return false;
}

void Country::operator[](int which)
{
	std::vector<Citizen>::iterator tempc = citizenArray.begin();
	std::vector<Town>::iterator tempt = townArray.begin();

	switch (which)
	{
	case 0:
		while (tempc != citizenArray.end())
		{
			(*tempc).showCitizen(*tempc);
			tempc++;
		}
		break;
	case 1:
		while (tempt != townArray.end())
		{
			(*tempt).showTown(*tempt);
			tempt++;
		}
		break;
	case 2:
		partner.showPartner(partner);
		break;
	}
}

bool Country::operator==(Country & a)
{
	if (a.partner.operator==(partner))
		return true;
	else
		return false;
}

std::ostream & operator<<(std::ostream & s, Country & c)
{
	s << c.name << std::endl;
	s << c.area << std::endl;
	s << c.continent << std::endl;
	s << c.partner;
	/*std::vector<Citizen>::iterator citizenit;	
	std::vector<Town>::iterator townit;
	for (citizenit = c.citizenArray.begin(); citizenit != c.citizenArray.end(); citizenit++)
		s << *citizenit;
	for (townit = c.townArray.begin(); townit != c.townArray.end(); townit++)
		s << *townit;
	*/
	return s;
}

std::istream & operator>>(std::istream & s, Country & c)
{
	s >> c.name;
	s >> c.area;
	s >> c.continent;
	s >> c.partner;
	
	/*Citizen citizen;
	s >> citizen;
	c.citizenArray.push_back(citizen);
	Town town;
	s >> town;
	c.townArray.push_back(town);*/
	return s;
}

Country::~Country()
{
	#ifdef _DEBUG
		std::cout << "Country class destructor fired.\n";
	#endif // _DEBUG
	
	citizenArray.clear();
	townArray.clear();
	amount_of_countries--;

	//delete[] citizenArray;
	//delete[] townArray;
	//citizenArray = nullptr;
	//townArray = nullptr;
}


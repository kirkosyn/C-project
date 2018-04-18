#include "Citizen.h"

Citizen::Citizen()
{
	#ifdef _DEBUG
		std::cout << "Citizen class default constructor fired.\n";
	#endif // _DEBUG

	name = "Karolina";
	surname = "Pawluk";
	age = 19;
	job = "unemployed";
	gender = "female";
}

Citizen::Citizen(std::string n, std::string s, std::string j, std::string g, int a)
{
	#ifdef _DEBUG
		std::cout << "Citizen class constructor with parameters fired.\n";
	#endif // _DEBUG
	name = n;
	surname = s;
	job = j;
	gender = g;
	age = a;
}


Citizen::Citizen(const Citizen & s)
{
	#ifdef _DEBUG
		std::cout << "Citizen class copy constructor fired.\n";
	#endif // _DEBUG
	age = s.age;
	name = s.name;
	surname = s.surname;
	job = s.job;
	gender = s.gender;
}

std::string Citizen::getName()
{
	return name;
}

std::string Citizen::getSurname()
{
	return surname;
}

int Citizen::getAge()
{
	return age;
}

std::string Citizen::getJob()
{
	return job;
}

std::string Citizen::getGender()
{
	return gender;
}

void Citizen::setName(std::string n)
{
	name = n;
}

void Citizen::setSurname(std::string s)
{
	surname = s;
}

void Citizen::setAge(int a)
{
	age = a;
}

void Citizen::setJob(std::string j)
{
	job = j;
}

void Citizen::setGender(std::string g)
{
	gender = g;
}

Citizen & Citizen::operator=(Citizen & p)
{
	name = p.getName();
	surname = p.getSurname();
	job = p.getJob();
	gender = p.getGender();
	age = p.getAge();
	return *this;
}

bool Citizen::operator>(Citizen & a) const
{
	if (a.age > age)
		return true;
	else return false;
}

bool Citizen::operator==(Citizen & a) const
{
	if (a.gender == "Male")
		return true;
	else
		return false;
}

void Citizen::showCitizen(Citizen & t)
{
	std::cout << "Citizen : " << t.name << " " << t.surname << std::endl;
	std::cout << "Gender : " << t.gender << std::endl;
	std::cout << "Age : " << t.age << std::endl;
	std::cout << "Job : " << t.job << "\n\n";
}

Citizen::~Citizen()
{
	#ifdef _DEBUG
		std::cout << "Citizen class destructor fired.\n";
	#endif // _DEBUG
}

std::ostream & operator<<(std::ostream & s, Citizen & c)
{
	s << c.name << std::endl;
	s << c.surname << std::endl;
	s << c.job << std::endl;
	s << c.gender << std::endl;
	s << c.age << std::endl;

	return s;
}

std::istream & operator>>(std::istream & s, Citizen & c)
{
	s >> c.name;
	s >> c.surname;
	s >> c.job;
	s >> c.gender;
	s >> c.age;

	return s;
}

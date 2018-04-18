#pragma once

///przestrzeñ statycznych testów
namespace staticTests 
{
	void countryTest();
	void citizenTest();
	void partnerCountryTest();
	void townTest();
}

///przestrzeñ dynamicznych testów
namespace dynamicTests
{
	void countryTest();
	void citizenTest();
	void partnerCountryTest();
	void townTest();
}

///przestrzeñ automatycznych testów
namespace automaticTests
{
	void countryTest();
	void citizenTest();
	void partnerCountryTest();
	void townTest();
	void landAreaTest();
	void waterAreaTest();
	void allClassesTest();
}

///przestrzeñ testów zapisuj¹cych do pliku
namespace writeToFileTests
{
	void countryTest();
	void landAreaTest();
	void waterAreaTest();
}

///przestrzeñ testów wczytuj¹cych z pliku
namespace readFromFileTests
{
	void countryTest();
	void landAreaTest();
	void waterAreaTest();
}
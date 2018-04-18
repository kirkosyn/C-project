#pragma once

///przestrze� statycznych test�w
namespace staticTests 
{
	void countryTest();
	void citizenTest();
	void partnerCountryTest();
	void townTest();
}

///przestrze� dynamicznych test�w
namespace dynamicTests
{
	void countryTest();
	void citizenTest();
	void partnerCountryTest();
	void townTest();
}

///przestrze� automatycznych test�w
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

///przestrze� test�w zapisuj�cych do pliku
namespace writeToFileTests
{
	void countryTest();
	void landAreaTest();
	void waterAreaTest();
}

///przestrze� test�w wczytuj�cych z pliku
namespace readFromFileTests
{
	void countryTest();
	void landAreaTest();
	void waterAreaTest();
}
#pragma once
#include <iostream>
#include <iomanip>

class Maszyna
{
	std::string nazwa;

public:
	Maszyna() :nazwa("Przyklad") {};
	void setNazwa(std::string _nazwa);
	std::string getNazwa() { return nazwa; };

	friend std::ostream& operator<<(std::ostream& out,const Maszyna& obiekt);
};

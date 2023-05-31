#pragma once
#include <string>
class Maszyna
{
	std::string nazwa;

public:
	void setNazwa(std::string _nazwa);
	std::string getNazwa() { return nazwa; };
};


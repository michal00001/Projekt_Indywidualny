#pragma once
#include <iostream>
#include <iomanip>
#include "Pole.h"
class Maszyna
{
	std::string nazwa;
	bool doUprawy;
	bool doSiewu;
	bool doNawozenia;
	bool doZbioru;

public:
	Maszyna() :nazwa("Przyklad"),doUprawy(false),doSiewu(false),doNawozenia(false),doZbioru(false) {};

	void setNazwa(std::string _nazwa);
	void setDoUprawy();
	void setDoSiewu();
	void setdDoNawozenia();
	void setDoZbioru();

	std::string getNazwa() { return nazwa; };

	void zasiej(Pole& _pole);
	void nawiez(Pole& _pole);
	void upraw(Pole& _pole);
	void zbierz(Pole& _pole);

	bool operator<(const Maszyna& _maszyna) const;

	friend std::ostream& operator<<(std::ostream& out,const Maszyna& obiekt);
};

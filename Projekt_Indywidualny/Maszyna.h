#pragma once
#include "Pole.h"

class Maszyna
{
private:
	std::string nazwa;
	bool doUprawy;
	bool doSiewu;
	bool doNawozenia;
	bool doZbioru;


public:
	Maszyna() :nazwa("Basic"), doUprawy(false), doSiewu(false), doNawozenia(false), doZbioru(false) {};
	void setNazwa(std::string _nazwa);
	void setDoUprawy();
	void setDoSiewu();
	void setdDoNawozenia();
	void setDoZbioru();

	std::string getNazwa() const { return nazwa; };
	bool getdoUprawy() const { return doUprawy; };
	bool getdoSiewu() const { return doSiewu; };
	bool getdoNawozenia() const { return doNawozenia; };
	bool getdoZbioru() const { return doZbioru; };

	void zasiej(Pole& _pole);
	void nawiez(Pole& _pole);
	void upraw(Pole& _pole);
	void zbierz(Pole& _pole);

	bool operator<(const Maszyna& _maszyna) const;
	bool operator==(const Maszyna& _maszyna) const;

};

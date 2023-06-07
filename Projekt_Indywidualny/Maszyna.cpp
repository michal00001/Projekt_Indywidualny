#include "Maszyna.h"

std::ostream& operator<<(std::ostream& out,const Maszyna& obiekt) {
	out.fill(' ');
	out<<obiekt.nazwa;
	return out;
}

void Maszyna::setNazwa(std::string _nazwa)
{
	nazwa = _nazwa;
}

void Maszyna::setDoUprawy()
{
	doUprawy = true;
	doSiewu = false;
	doNawozenia = false;
	doZbioru = false;
	nazwa = "Kultywator";
}

void Maszyna::setDoSiewu()
{
	doUprawy = false;
	doSiewu = true;
	doNawozenia = false;
	doZbioru = false;
	nazwa = "Siewnik";
}

void Maszyna::setdDoNawozenia()
{
	doUprawy = false;
	doSiewu = false;
	doNawozenia = true;
	doZbioru = false;
	nazwa = "Rozsiewacz";
}

void Maszyna::setDoZbioru()
{
	doUprawy = false;
	doSiewu = false;
	doNawozenia = false;
	doZbioru = true;
	nazwa = "Kombajn";
}

void Maszyna::zasiej(Pole& _pole) {
	if (doSiewu)
	{
		_pole.setstadiumWzrostu(1);
		_pole.setUprawiono(0);
		_pole.setNawieziono(_pole.czyNawieziono());
		_pole.setZasiano(1);
		_pole.setZebrano(0);
	}
}

void Maszyna::nawiez(Pole& _pole)
{
	if (doNawozenia && (_pole.getstadiumWzrostu()<6))
	{
		//_pole.setstadiumWzrostu(1);
		//_pole.setUprawiono(0);
		_pole.setNawieziono(1);
		//_pole.setZasiano(1);
		//_pole.setZebrano(0);
	}
}

void Maszyna::upraw(Pole& _pole)
{
	if (doUprawy)
	{
		_pole.setstadiumWzrostu(0);
		_pole.setUprawiono(1);
		_pole.setNawieziono(_pole.czyNawieziono());
		_pole.setZasiano(0);
		_pole.setZebrano(0);
	}
}

void Maszyna::zbierz(Pole& _pole)
{
	if (doZbioru)
	{
		_pole.setstadiumWzrostu(0);
		_pole.setUprawiono(0);
		_pole.setNawieziono(0);
		_pole.setZasiano(0);
		_pole.setZebrano(1);
	}
}

bool Maszyna::operator<(const Maszyna& _maszyna) const
{
	if (nazwa > _maszyna.nazwa)
		return false;
	else
		return true;
}

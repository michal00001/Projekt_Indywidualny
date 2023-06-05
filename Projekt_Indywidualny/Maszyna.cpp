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

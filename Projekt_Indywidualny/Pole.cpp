#include "Pole.h"

std::ostream& operator<<(std::ostream& out,const Pole& obiekt) {
	out.fill(' ');
	out << obiekt.nazwa << " " << obiekt.powierzchnia << " " << obiekt.stadiumWzrostu;
	return out;
}

void Pole::setNazwa(std::string _nazwa)
{
	nazwa = _nazwa;
}

void Pole::setstadiumWzrostu(int _stadiumWzrostu)
{
	if (_stadiumWzrostu >= 0 && _stadiumWzrostu < 7)
		stadiumWzrostu = _stadiumWzrostu;
	//0 - brak uprawy
	// 1 - zasiane
	// 2 - kielkowanie
	// 3 - jeden listek
	// 4 - wiecej listkow
	// 5 - prawie gotowe
	// 6 - gotowe do zbioru
	// 7 - uschniete (nasiona opadly z klosow)
}

void Pole::setPowierzchnia(float _powierzchnia)
{
	if (_powierzchnia > 0)
		powierzchnia = _powierzchnia;
}

void Pole::setUprawiono(bool _stan)
{
	uprawiono = _stan;
}

void Pole::setNawieziono(bool _stan)
{
	nawieziono = _stan;
}

void Pole::setZasiano(bool _stan)
{
	zasiano = _stan;
}

void Pole::setZebrano(bool _stan)
{
	zebrano = _stan;
}

bool Pole::operator<(const Pole& _obiekt) const
{
	if (powierzchnia > _obiekt.powierzchnia)
		return false;
	else
		return true;
}


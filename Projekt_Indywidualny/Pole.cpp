#include "Pole.h"

std::ostream& operator<<(std::ostream& out,const Pole& obiekt) {
	out.fill(' ');
	out << obiekt.nazwa << " " << std::setprecision(5)<< obiekt.powierzchnia << " [ha]" << " " << obiekt.stadiumWzrostu;
	return out;
}

void Pole::setNazwa(std::string _nazwa)
{
	nazwa = _nazwa;
}

void Pole::setstadiumWzrostu(int _stadiumWzrostu)
{
	if (_stadiumWzrostu >= 0 && _stadiumWzrostu <= 7)
		stadiumWzrostu = _stadiumWzrostu;
	else
		throw std::out_of_range("Wartosc stadium wzrostu jest spoza zakresu <0,7>");
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
	else
		throw std::domain_error("Powierzchnia pola jest <= 0");
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
	return (powierzchnia < _obiekt.powierzchnia);
}


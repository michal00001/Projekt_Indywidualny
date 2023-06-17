#include "Pole.h"

Pole::Pole(std::string _nazwa, float powierzchnia)
{
	setNazwa(_nazwa);
	setPowierzchnia(powierzchnia);
	stadiumWzrostu = 0;//liczba od 0 do 7
	uprawiono = 0;
	nawieziono = 0;
	zasiano = 0;
	zebrano = 0;
}

void Pole::setNazwa(std::string _nazwa)
{
	nazwa = _nazwa;
}

void Pole::setstadiumWzrostu(int _stadiumWzrostu)
{
	if (_stadiumWzrostu >= 0 && _stadiumWzrostu <= 7)
		stadiumWzrostu = _stadiumWzrostu;
	/*else
		throw std::out_of_range("Wartosc stadium wzrostu jest spoza zakresu <0,7>");*/
	// 0 - brak uprawy
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
		powierzchnia = 0.0;
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

void Pole::wyzerujStanPola()
{
	uprawiono = false;
	nawieziono = false;
	zasiano = false;
	zebrano = false;
	stadiumWzrostu = 0;
}

bool Pole::operator<(const Pole& _obiekt) const
{
	return (powierzchnia < _obiekt.powierzchnia);
}

bool Pole::operator==(const Pole& _obiekt) const
{
	if (nazwa == _obiekt.nazwa)
		return true;
	else
		return false;
}


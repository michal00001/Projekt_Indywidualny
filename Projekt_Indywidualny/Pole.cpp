#include "Pole.h"

std::ostream& operator<<(std::ostream& out,const Pole& obiekt) {
	out.fill(' ');
	out << obiekt.nazwa << ";";	out << obiekt.powierzchnia << ";" << obiekt.klasa;
	return out;
}

void Pole::setNazwa(std::string _nazwa)
{
	nazwa = _nazwa;
}

void Pole::setKlasa(int _klasa)
{
	if (_klasa > 0 && _klasa < 7)
		klasa = _klasa;
}

void Pole::setPowierzchnia(float _powierzchnia)
{
	if (_powierzchnia > 0)
		powierzchnia = _powierzchnia;
}


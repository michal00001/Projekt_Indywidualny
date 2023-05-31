#include "Pole.h"

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


#include "Pole.h"

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

void Pole::wprowadzDane()
{
	using namespace std;
	string _nazwa;
	float _powierzchnia;
	bool warunekWhile = true;
	
	system("cls");
	cout << "Podaj nazwe pola: " << endl;
	cin >> _nazwa;
	
	system("cls");
	cout << "Podana nazwa pola to " << _nazwa << endl;
	cout << "Podaj powierzchnie pola: " << endl;
	while (1) { //nieskoñczona pêtla
		cin >> _powierzchnia; //pobranie zmiennej
		if (cin.fail() == true || _powierzchnia <= 0) { //wykrycie b³êdu
			cout << "Prosze podac poprawna wartosc" << endl; //komunikat o b³êdzie
			cin.clear(); //resetowanie flag b³êdu
			cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
		} //lub do napotkania znaku nowej linii
		else break;
	}

	setNazwa(_nazwa);
	setPowierzchnia(_powierzchnia);
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


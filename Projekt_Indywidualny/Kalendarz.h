#pragma once
#include <list>
#include <fstream>
#include "Zabieg.h"
#include <string>

class Kalendarz
{
	std::list<Zabieg> listaZabiegow;

public:
	void sortujZabiegi(const Data& _data);
	//void sortujZabiegi(const Maszyna& _nazwa);
	//void sortujZabiegi(const Pole& _powierzchnia);

	void dodajZabieg(Zabieg _obiekt);
	void usunZabieg(int _pozycja);

	void odczytajZabiegZPliku(char* _sciezka);
    
	void wyczyscListeZabiegow();

	bool czyListaPusta();
	std::size_t getsizelistaZabiegowa() const { return listaZabiegow.size(); };

};


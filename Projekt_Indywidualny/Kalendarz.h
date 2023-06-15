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
	void sortujZabiegi(const Maszyna& _nazwa);
	void sortujZabiegi(const Pole& _powierzchnia);

	void dodajZabieg();
	void dodajZabieg(Zabieg _obiekt);
	void dodajZabieg(char* _sciezka);

	void usunZabieg(int _pozycja);
	void wyczyscListeZabiegow();

	bool czyListaPusta();
	std::list<Zabieg>& getlistaZabiegow() { return listaZabiegow; }; 
	std::size_t getsizelistaZabiegowa() const { return listaZabiegow.size(); };
};


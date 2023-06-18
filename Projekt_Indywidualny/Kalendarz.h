#pragma once
#include <list>
#include <string>
#include <sstream>
#include <fstream>

#include "Zabieg.h"
#include "Drukarka.h"

class Kalendarz
{
	std::list<Zabieg> listaZabiegow;

public:
	void sortujZabiegi(const Data& _data);
	//void sortujZabiegi(const Maszyna& _nazwa);
	//void sortujZabiegi(const Pole& _powierzchnia);

	std::list<Zabieg>::iterator getZabieg(int _indeks);

	void dodajZabieg(Zabieg _obiekt);
	void usunZabieg(int _pozycja);
	void edytujZabieg(std::list<Zabieg>::iterator _zabieg, Data _data, Maszyna* _maszyna, Pole* _pole);
	void ZapiszZabiegiCSV(const char* _sciezka);
	void odczytajZabiegZPliku(const char* _sciezka);
    
	void wyswietlListeZabiegow();
	void wyswietlListeZabiegow(int _ile);
	void wyczyscListeZabiegow();

	bool sprawdzCzyNieWystepuj(Zabieg& _obiekt);
	std::size_t getsizelistaZabiegowa() const { return listaZabiegow.size(); };

};


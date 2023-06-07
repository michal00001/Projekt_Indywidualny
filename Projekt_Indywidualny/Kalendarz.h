#pragma once
#include <list>
#include <fstream>
#include "Zabieg.h"
#include <string>

class Kalendarz
{
	std::list<Zabieg> listaZabiegow;
	std::list<Zabieg>::iterator K_Iter;

public:
	void sortujZabiegi(const Data& _data);
	void sortujZabiegi(const Maszyna& _nazwa);
	void sortujZabiegi(const Pole& _powierzchnia);

	void dodajZabieg();
	void dodajZabieg(Zabieg _obiekt);
	void dodajZabieg(char* _sciezka);

	std::list<Zabieg>& getlistaZabiegow() { return listaZabiegow; };

	//zrob z tego osobn¹ klasê DrukarkaFactory 
	//drukowanie do .txt , do .csv
	void wydrukujlistaZabiegow();
	void wydrukujlistaZabiegow(char* _sciezka);
	void wydrukujlistaZabiegow(char* _sciezka,bool _csv);


};


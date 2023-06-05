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
	void sortujZabiegi();

	void dodajZabieg();
	void dodajZabieg(Zabieg _obiekt);
	void dodajZabieg(char* _sciezka);

	void wydrukujlistaZabiegow();
	void wydrukujlistaZabiegow(char* _sciezka);
	void wydrukujlistaZabiegow(char* _sciezka,bool _csv);


};


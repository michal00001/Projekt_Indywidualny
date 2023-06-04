#pragma once
#include <list>
#include <fstream>
#include "Zabieg.h"

class Kalendarz
{
	std::list<Zabieg> Kalendarz;
	std::list<Zabieg>::iterator K_Iter;

public:

	void dodajZabieg();
	void dodajZabieg(Zabieg _obiekt);
	void dodajZabieg(char* _sciezka);

	void wydrukujKalendarz();
	void wydrukujKalendarz(char* _sciezka);
	void wydrukujKalendarz(char* _sciezka,bool _csv);

};


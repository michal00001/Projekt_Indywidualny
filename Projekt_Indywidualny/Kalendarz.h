#pragma once
#include <list>
#include "Zabieg.h"
#include <iostream>

class Kalendarz
{
	std::list<Zabieg> Kalendarz;
	std::list<Zabieg>::iterator K_Iter;

public:

	void dodajZabieg();
	void dodajZabieg(std::ifstream plik);

	void wydrukujKalendarz();
	void wydrukujKalendarz(std::ofstream plik);

};


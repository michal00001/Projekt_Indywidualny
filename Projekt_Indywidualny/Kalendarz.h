#pragma once
#include <list>
#include "Zabieg.h"
#include <iostream>
#include <fstream>
class Kalendarz
{
	std::list<Zabieg> Kalendarz;
	std::list<Zabieg>::iterator K_Iter;

public:

	void dodajZabieg();
	void dodajZabieg(char* _sciezka);

	void wydrukujKalendarz();
	void wydrukujKalendarz(char* _sciezka);

};


#pragma once
#include <vector>
#include "Zabieg.h"
#include <iostream>




class Kalendarz
{
	std::vector<Zabieg> kalendarz;

public:
	void dodajZabieg();

	void wydrukujKalendarz();
	void wydrukujKalendarz(std::ofstream plik);

};


#pragma once

#include <iostream>
#include <string>

#include "Data.h"
#include "Maszyna.h"
#include "Pole.h"

class Zabieg
{
private:
	Data data;
	Maszyna* maszyna;
	Pole* pole;

public:
	Zabieg() :data(1, 1, 1901), maszyna(nullptr), pole(nullptr) {} ;

	Data& getData() { return data; };
	Maszyna* getMaszyna() { return maszyna; };
	Pole* getPole() { return pole; };

	static bool czyPoprawny( Data& _data);

	void setData(Data _data);
	void setData(int _dzien, int _miesiac, int _rok);
	void setMaszyna(Maszyna* _obiekt);
	void setPole(Pole* _obiekt);

	void wykonajZabieg(int _opcja);
	void wyswietl();
};



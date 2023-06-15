#pragma once

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
	Zabieg(Data _data, Maszyna _maszyna, Pole _pole);

	/*void ustawDate();
	void ustawMaszyn();
	void ustawPole();*/

	Data& getData() { return data; };


	bool czyPoprawny(Data& _data) const ;
	bool czyPoprawny( Pole& _pole) const ;
	bool czyPoprawny( Maszyna& _maszyna) const ;

	void setData(int _dzien, int _miesiac, int _rok);


};



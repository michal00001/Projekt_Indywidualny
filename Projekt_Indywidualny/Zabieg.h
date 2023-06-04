#pragma once

#include "Data.h"
#include "Maszyna.h"
#include "Pole.h"

class Zabieg
{
private:
	Data data;
	Maszyna maszyna;
	Pole pole;

public:
	Zabieg() :data(1, 1, 1901), maszyna(), pole() {} ;
	Zabieg(Data _data, Maszyna _maszyna, Pole _pole);

	const Data& getData() {	return data;};
	const Maszyna& getMaszyna() {	return maszyna;};
	const Pole& getPole() {		return pole;};

	//void setData(int _dzien);
	//void setData(int _dzien, int _miesiac);
	void setData(int _dzien, int _miesiac, int _rok);

	void setMaszyna(std::string _nazwa);

	//void setPole(float _powierzchnia);
	//void setPole(float _powierzchnia,std::string _nazwa);
	void setPole(float _powierzchnia, std::string _nazwa, int _klasa);

	friend std::ostream& operator<<(std::ostream& out,const Zabieg& obiekt);
};



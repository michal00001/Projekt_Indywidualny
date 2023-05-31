#pragma once
#include <iostream>
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

	std::string getData();
	std::string getMaszyna();
	std::string getPole();

	//void setData(int _dzien);
	//void setData(int _dzien, int _miesiac);
	void setData(int _dzien, int _miesiac, int _rok);

	void setMaszyna(std::string _nazwa);

	//void setPole(float _powierzchnia);
	//void setPole(float _powierzchnia,std::string _nazwa);
	void setPole(float _powierzchnia, std::string _nazwa, int _klasa);

};



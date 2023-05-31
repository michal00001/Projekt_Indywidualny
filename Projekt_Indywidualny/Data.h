#pragma once
#include <string>

class Data
{
private:
	int dzien;
	int miesiac;
	int rok;
public:
	Data() :dzien(0), miesiac(0), rok(0) {};
	//Data(int _dzien);
	//Data(int _dzien, int _miesiac);
	Data(int _dzien, int _miesiac, int _rok);

	//fragmenty biblioteki QuantLib
	//problem z dodaniem do Visuala
	bool isLeap(int _rok);
	int monthLength(int _miesiac, bool leapYear);

	void setDzien(int _dzien);
	void setMiesiac(int _miesiac);
	void setRok(int _rok);

	int getDzien() { return dzien; };
	int getMiesiac() { return miesiac; };
	int getRok() { return rok; };

	bool operator>(Data& _obiekt);
	bool operator<(Data& _obiekt);
	bool operator>=(Data& _obiekt);
	bool operator<=(Data& _obiekt);
	bool operator==(Data& _obiekt);
	bool operator!=(Data& _obiekt);


};


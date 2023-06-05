#pragma once
#include <iostream>
#include <iomanip>


class Data
{
private:
	int dzien;
	int miesiac;
	int rok;
public:
	Data() :dzien(1), miesiac(1), rok(1901) {};
	Data(int _dzien, int _miesiac, int _rok);
	//Data(int _dzien);
	//Data(int _dzien, int _miesiac);


	//fragmenty biblioteki QuantLib
	//problem z dodaniem do Visuala
	bool isLeap(int _rok);
	int monthLength(int _miesiac, bool leapYear);
	std::string ktoryMiesiac(int _miesiac);


	void setDzien(int _dzien);
	void setMiesiac(int _miesiac);
	void setRok(int _rok);

	int getDzien() { return dzien; };
	int getMiesiac() { return miesiac; };
	int getRok() { return rok; };

	bool operator>(const Data& _obiekt) const;
	bool operator<(const Data& _obiekt) const;

	bool operator>=(const Data& _obiekt) const;
	bool operator<=(const Data& _obiekt) const;
	bool operator==(const Data& _obiekt) const;
	bool operator!=(const Data& _obiekt) const;

	friend std::ostream& operator<<(std::ostream& out, const Data& obiekt);
};
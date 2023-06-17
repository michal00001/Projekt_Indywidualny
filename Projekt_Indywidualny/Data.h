#pragma once
#include <iomanip>

class Data
{
private:
	int dzien;
	int miesiac;
	int rok;
public:
	//konstruktory
	Data() :dzien(1), miesiac(1), rok(1901) {};
	Data(int _dzien, int _miesiac, int _rok);

	//fragmenty biblioteki QuantLib
	//problem z dodaniem do Visuala
	static bool isLeap(int _rok);
	static int monthLength(int _miesiac, bool leapYear);
	std::string ktoryMiesiac(int _miesiac);

	//akcesory
	void setDzien(int _dzien);
	void setMiesiac(int _miesiac);
	void setRok(int _rok);

	const int getDzien() { return dzien; };
	const int getMiesiac() { return miesiac; };
	const int getRok() { return rok; };

	//operatory porownania
	bool operator>(const Data& _obiekt) const;
	bool operator<(const Data& _obiekt) const;
	bool operator>=(const Data& _obiekt) const;
	bool operator<=(const Data& _obiekt) const;
	bool operator==(const Data& _obiekt) const;
	bool operator!=(const Data& _obiekt) const;

	friend std::ostream& operator<<(std::ostream& out, const Data& obiekt);
};
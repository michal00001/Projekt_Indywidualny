#pragma once
class Data
{
private:
	int dzien;
	int miesiac;
	int rok;
public:
	void setDzien(int _x);
	void setMiesiac(int _x);
	void setRok(int _x);

	int getDzien() { return dzien; };
	int getMiesiac() { return miesiac; };
	int getRok() { return rok; };
};


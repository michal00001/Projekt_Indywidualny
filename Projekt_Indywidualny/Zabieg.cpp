#include "Zabieg.h"

std::ostream& operator<<(std::ostream& out,const Zabieg& obiekt) {
	out << obiekt.data << " "  << obiekt.maszyna << " "  << obiekt.pole;

	return out;
}

Zabieg::Zabieg(Data _data, Maszyna _maszyna, Pole _pole)
{
	//if(_data.czyPoprawny())
	data = _data;
	//if(_maszyna.czyPoprawny())
	maszyna = _maszyna;
	//if(_pole.czyPoprawny())
	pole = _pole;
}

bool Zabieg::czyPoprawny(Data& _data) const
{
	int dlugosc = _data.monthLength(_data.getMiesiac(), _data.isLeap(_data.getRok()));

	//if(_data == nullptr) return false;
	if (_data.getRok() <= 1900 || _data.getRok() >= 2200)		return false;
	if (_data.getMiesiac() <= 0 || _data.getMiesiac() >= 13)		return false;
	if (_data.getDzien() > dlugosc || _data.getDzien() <= 0)		return false;
		
	return true;
}

bool Zabieg::czyPoprawny(Pole& _pole) const
{
	//if(_pole == nullptr) return false;
	if(_pole.getPowierzchnia() <= 0)		return false;
	if (_pole.getstadiumWzrostu() < 0 || _pole.getstadiumWzrostu() > 6)		return false;
	
	return true;
}

bool Zabieg::czyPoprawny(Maszyna& _maszyna) const
{
	//if(_maszyna == nullptr) return false;
	return true;
}

void Zabieg::setData(int _dzien,int _miesiac, int _rok)
{
	data.setDzien(_dzien);
	data.setMiesiac(_miesiac);
	data.setRok(_rok);
}

void Zabieg::setMaszyna(std::string _nazwa)
{
	//maszyna.setNazwa(_nazwa);
}

void Zabieg::setPole(float _powierzchnia, std::string _nazwa, int _stadiumWzrostu)
{
	pole.setPowierzchnia(_powierzchnia);
	pole.setNazwa(_nazwa);
	pole.setstadiumWzrostu(_stadiumWzrostu);
}

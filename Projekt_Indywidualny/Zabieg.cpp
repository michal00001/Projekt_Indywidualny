#include "Zabieg.h"

std::ostream& operator<<(std::ostream& out,const Zabieg& obiekt) {
	//out << "| " << obiekt.data << "  |" << std::setw(23) << obiekt.maszyna << "|" << std::setw(42) << obiekt.pole << "|";
	out << obiekt.data << ";"  << obiekt.maszyna << ";"  << obiekt.pole;

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

void Zabieg::setData(int _dzien,int _miesiac, int _rok)
{
	data.setDzien(_dzien);
	data.setMiesiac(_miesiac);
	data.setRok(_rok);
}

void Zabieg::setMaszyna(std::string _nazwa)
{
	maszyna.setNazwa(_nazwa);
}

void Zabieg::setPole(float _powierzchnia, std::string _nazwa, int _stadiumWzrostu)
{
	pole.setPowierzchnia(_powierzchnia);
	pole.setNazwa(_nazwa);
	pole.setstadiumWzrostu(_stadiumWzrostu);
}

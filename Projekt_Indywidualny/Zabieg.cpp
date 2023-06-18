#include "Zabieg.h"

bool Zabieg::czyPoprawny(Data& _data)
{
	int dlugosc = _data.monthLength(_data.getMiesiac(), _data.isLeap(_data.getRok()));

	if (_data.getRok() <= 1900 || _data.getRok() >= 2200)		return false;
	if (_data.getMiesiac() <= 0 || _data.getMiesiac() >= 13)		return false;
	if (_data.getDzien() > dlugosc || _data.getDzien() <= 0)		return false;
		
	return true;
}

void Zabieg::setData(Data _data)
{
	data = _data;
}

void Zabieg::setData(int _dzien,int _miesiac, int _rok)
{
	try {
	data.setDzien(_dzien);
	data.setMiesiac(_miesiac);
	data.setRok(_rok);
	}
	catch (std::out_of_range& exc)
	{
		std::cerr << exc.what() << std::endl;
		setData(Data(1, 1, 1901));
		std::cout << "Data zostala ustawiona na wartosc domyslna [01.01.1901] zmien ja pozniej w menu edycji" << std::endl;
			
	}
}

void Zabieg::setMaszyna(Maszyna* _obiekt)
{
	if (_obiekt)
	{
		maszyna = _obiekt;
	}
}

void Zabieg::setPole(Pole* _obiekt)
{
	if (_obiekt)
	{
		pole = _obiekt;
	}
}

void Zabieg::wykonajZabieg(int _opcja)
{
	
	switch (_opcja) {
	case 1:
		maszyna->nawiez(pole);
		break;
	case 2:
		maszyna->upraw(pole);
		break;
	case 3:
		maszyna->zasiej(pole);
		break;
	case 4:
		maszyna->zbierz(pole);
		break;
	default:
		break;
	}
}

void Zabieg::wyswietl() {
	std::cout << data<<std::endl;

	std::cout << "|" << pole->getNazwa() << "|" << std::to_string(pole->getPowierzchnia()) << "|" << pole->getstadiumWzrostu() << "|";
	if (pole->czyNawieziono()) std::cout << "Nawieziono";
	else if (pole->czyUprawiono()) std::cout << "Uprawiono";
	else if (pole->czyZasiano()) std::cout << "Zasiano";
	else if (pole->czyZebrano()) std::cout << "Zebrano";
	else std::cout << "Ugor";
	std::cout << "|" << std::endl;

	std::cout << maszyna->getNazwa() << std::endl;

}
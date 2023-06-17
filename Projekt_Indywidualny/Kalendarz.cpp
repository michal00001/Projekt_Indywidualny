#include "Kalendarz.h"

void Kalendarz::sortujZabiegi(const Data& _data)
{
	listaZabiegow.sort([](Zabieg& a, Zabieg& b) ->bool {return a.getData() < b.getData();});

	//[] funkcja lamba 
	// pozwala definiowac funkcje bezposrednio w miejscu ich uzycia np jako argumenty
	// skladnia
	//[capture list](parameters) -> return type { function body }


	//funkcja sort() jako argument przyjmuje funckje typu 
	//bool cmp(const Type1 &a, const Type2 &b)
	// gdzie wartoscia zwracana jest miejsce wartosc boolowska 
}

//void Kalendarz::sortujZabiegi(const Pole& _powierzchnia)
//{
//	listaZabiegow.sort([](Zabieg& a, Zabieg& b) ->bool {return a.getPole() < b.getPole(); });
//}
//
//void Kalendarz::sortujZabiegi(const Maszyna& _nazwa) {
//	listaZabiegow.sort([](Zabieg& a, Zabieg& b) ->bool {return a.getMaszyna() < b.getMaszyna(); });
//}

void Kalendarz::dodajZabieg(Zabieg _obiekt)
{
	listaZabiegow.push_back(_obiekt);
	sortujZabiegi(Data());
}

void Kalendarz::usunZabieg(int _pozycja)
{
	auto iterator = listaZabiegow.begin();
	for (int i = 0; i < _pozycja; i++)
	{
		iterator++;
	}
	listaZabiegow.erase(iterator);
}

void Kalendarz::wyczyscListeZabiegow()
{
	listaZabiegow.clear();
}

bool Kalendarz::czyListaPusta()
{
	if (listaZabiegow.size() > 0)
		return false;
	else
		return true;
}

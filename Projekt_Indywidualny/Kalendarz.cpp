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

std::list<Zabieg>::iterator Kalendarz::getZabieg(int _indeks)
{
	//niebezpieczna funkcja
	std::list<Zabieg>::iterator iterator = listaZabiegow.begin();
	for (int i = 0; i < _indeks; i++)
	{
		iterator++;
	}
	return iterator;
}

void Kalendarz::dodajZabieg(Zabieg _obiekt)
{
	listaZabiegow.push_back(_obiekt);
	sortujZabiegi(Data());
}


void Kalendarz::usunZabieg(int _pozycja)
{
	std::list<Zabieg>::iterator iterator = listaZabiegow.begin();
	for (int i = 0; i < _pozycja; i++)
	{
		iterator++;
	}
	listaZabiegow.erase(iterator);
}

void Kalendarz::edytujZabieg(std::list<Zabieg>::iterator _zabieg, Data _data)
{
	if (Zabieg::czyPoprawny(_data))
	{

	}
	_zabieg->setData(_data);
}

void Kalendarz::ZapiszZabiegiCSV(const char* _sciezka)
{
	try
	{
	std::unique_ptr<Drukarka> drukarka = DrukarkaFactory<CSVDrukarka>::stworzDrukarke();
	drukarka->drukuj(listaZabiegow,(int)listaZabiegow.size());
	}
	catch (const std::domain_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Kalendarz::odczytajZabiegZPliku(const char* _sciezka)
{

}

void Kalendarz::wyswietlListeZabiegow()
{
	std::unique_ptr<Drukarka> drukarka = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	drukarka->drukuj(listaZabiegow, listaZabiegow.size());
}

void Kalendarz::wyswietlListeZabiegow(int _ile)
{
	std::unique_ptr<Drukarka> drukarka = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	drukarka->drukuj(listaZabiegow, _ile);
}

void Kalendarz::wyczyscListeZabiegow()
{
	listaZabiegow.clear();
}


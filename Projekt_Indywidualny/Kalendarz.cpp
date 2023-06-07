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

void Kalendarz::sortujZabiegi(const Pole& _powierzchnia)
{
	listaZabiegow.sort([](Zabieg& a, Zabieg& b) ->bool {return a.getPole() < b.getPole(); });
}

void Kalendarz::sortujZabiegi(const Maszyna& _nazwa) {
	listaZabiegow.sort([](Zabieg& a, Zabieg& b) ->bool {return a.getMaszyna() < b.getMaszyna(); });
}

void Kalendarz::dodajZabieg()
{
	Zabieg temp;

	std::cout << "Podaj dzien, miesiac i rok" << std::endl;
	int dzie, mies, rok,klasa;
	std::cin >> dzie >> mies >> rok;
	temp.setData(dzie,mies,rok);

	std::string nazwa;
	std::cout << "Podaj nazwe maszyny" << std::endl;
	std::cin >> nazwa;
	temp.setMaszyna(nazwa);

	std::cout << "Podaj powierzchnia, nazwa i klase pola" << std::endl;
	float powi;
	std::cin >> powi >> nazwa >> klasa;
	temp.setPole(powi,nazwa,klasa);

	listaZabiegow.push_back(temp);
}

void Kalendarz::dodajZabieg(Zabieg _obiekt)
{
	//if(_obiekt.poprawny)
	listaZabiegow.push_back(_obiekt);
	//listaZabiegow.sort();
}

void Kalendarz::dodajZabieg(char* _sciezka)
{
	int i = 0;
	int dzien, miesiac, rok,klasaPola;
	float powierzchniaPola;
	std::string nazwaMaszyny, nazwaPola;
	std::fstream plik;
	//char bufor[256] = { "\n" };//
	std::string bufor;
	plik.open(_sciezka, std::ofstream::in);

	if (!plik.is_open())
		return; //blad 
	std::getline(plik, bufor);
	if (bufor == "Zapis danych")
	{
		std::cout << "Sukces\n";
		std::getline(plik, bufor);


		while (plik.good()) {

			std::getline(plik, bufor, '.');
			dzien = stoi(bufor);
			std::getline(plik, bufor, '.');
			miesiac = stoi(bufor);
			std::getline(plik, bufor, ';');
			rok = stoi(bufor);
			std::getline(plik, bufor, ';');
			nazwaMaszyny = bufor;
			std::getline(plik, bufor, ';');
			nazwaPola = bufor;
			std::getline(plik, bufor, ';');
			powierzchniaPola = stof(bufor);
			std::getline(plik, bufor);
			klasaPola = stoi(bufor);
			
			Zabieg zabieg;
			zabieg.setData(dzien, miesiac, rok);
			zabieg.setMaszyna(nazwaMaszyny);
			zabieg.setPole(powierzchniaPola, nazwaPola, klasaPola);
			listaZabiegow.push_back(zabieg);
			i++;
			std::cout << i<<"\n";
		}
	}
	Data _data;
	sortujZabiegi(_data);

	plik.close();
}

void Kalendarz::wydrukujlistaZabiegow()
{
	
}

void Kalendarz::wydrukujlistaZabiegow(char* _sciezka)
{
	
}

void Kalendarz::wydrukujlistaZabiegow(char* _sciezka,bool _csv)
{
	
}

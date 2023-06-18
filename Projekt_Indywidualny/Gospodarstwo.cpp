#include "Gospodarstwo.h"

void Gospodarstwo::dodajMaszyne(Maszyna _obiekt)
{
	if (sprawdzCzyNieWystepuje(_obiekt))
		ParkMaszynowy.push_back(_obiekt);
}

void Gospodarstwo::usunMaszyne(int _pozycja)
{
	auto iterator = ParkMaszynowy.begin()+_pozycja;
	ParkMaszynowy.erase(iterator);
}

void Gospodarstwo::zapiszMaszynyCSV(const char* _sciezka)
{
	std::unique_ptr<Drukarka> drukarka = DrukarkaFactory<CSVDrukarka>::stworzDrukarke();
	drukarka->drukuj(ParkMaszynowy,(int) ParkMaszynowy.size(), _sciezka);
}

void Gospodarstwo::wyswietlListeMaszyn()
{
	std::unique_ptr<Drukarka> drukara = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	drukara->drukuj(ParkMaszynowy,(int)ParkMaszynowy.size());
}

void Gospodarstwo::wyswietlListeMaszyn(int _ile)
{
	std::unique_ptr<Drukarka> drukara = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	drukara->drukuj(ParkMaszynowy, _ile);
}

void Gospodarstwo::wyswietlListePol()
{
	std::unique_ptr<Drukarka> drukara = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	drukara->drukuj(ZiemiaUprawna,(int) ZiemiaUprawna.size());
}

void Gospodarstwo::wyswietlListePol(int _ile)
{
	std::unique_ptr<Drukarka> drukara = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	drukara->drukuj(ZiemiaUprawna,_ile);
}

void Gospodarstwo::dodajPole(Pole _obiekt)
{
	if (sprawdzCzyNieWystepuje(_obiekt))
		ZiemiaUprawna.push_back(_obiekt);
}

void Gospodarstwo::edytujPole(Pole& pole,std::string _nazwa,float _powierzchnia)
{
	pole.setNazwa(_nazwa);
	pole.setPowierzchnia(_powierzchnia);
}

void Gospodarstwo::usunPole(int _pozycja)
{
	auto iterator = ZiemiaUprawna.begin() + _pozycja;
	ZiemiaUprawna.erase(iterator);
}

void Gospodarstwo::zapiszPoleCSV(const char* _sciezka)
{
	std::unique_ptr<Drukarka> drukarka = DrukarkaFactory<CSVDrukarka>::stworzDrukarke();
	drukarka->drukuj(ZiemiaUprawna,(int) ZiemiaUprawna.size(), _sciezka);
}

Maszyna& Gospodarstwo::getMaszyna(int _indeks)
{
	return ParkMaszynowy.at(_indeks);
}

Pole& Gospodarstwo::getPole(int _indeks)
{
	return ZiemiaUprawna.at(_indeks);;
}

bool Gospodarstwo::sprawdzCzyNieWystepuje(Maszyna& _obiekt) const
{
	for (int i = 0; i < ParkMaszynowy.size(); i++)
	{
		if (ParkMaszynowy[i] == _obiekt)
			return false;
	}
	return true;
}

bool Gospodarstwo::sprawdzCzyNieWystepuje(Pole& _obiekt) const
{
	for (int i = 0; i < ZiemiaUprawna.size(); i++)
	{
		if (ZiemiaUprawna[i] == _obiekt)
			return false;
	}
	return true;
}

void Gospodarstwo::wyczyscGospodarstwo()
{
	ZiemiaUprawna.clear();
	ParkMaszynowy.clear();
}

void Gospodarstwo::odczytajMaszynyZPliku(const char* sciezka)
{
		std::ifstream plik(sciezka);
		if (!plik)
		{
			std::cout << "B³¹d otwarcia pliku "<<sciezka << std::endl;
			return;
		}

		std::deque<Maszyna> kolejka;

		// Pomijamy nag³ówki kolumn
		std::string linia;
		std::string naglowek = "Nazwa;doUprawy;doSiewu;doNawozenia;doZbioru";
		std::getline(plik, linia);
		if (linia != naglowek) {
			plik.close();
			std::cout << "Plik "<<sciezka<<" nie zawiera poprawnie sformatowanych danych." << std::endl;
			return;
		}

		while (std::getline(plik, linia)) {
			std::string nazwa, doUprawyStr, doSiewuStr, doNawozeniaStr, doZbioruStr;
			bool doUprawy, doSiewu, doNawozenia, doZbioru;

			std::stringstream ss(linia);
			std::getline(ss, nazwa, ';');
			std::getline(ss, doUprawyStr, ';');
			std::getline(ss, doSiewuStr, ';');
			std::getline(ss, doNawozeniaStr, ';');
			std::getline(ss, doZbioruStr, ';');

			doUprawy = (doUprawyStr == "Tak");
			doSiewu = (doSiewuStr == "Tak");
			doNawozenia = (doNawozeniaStr == "Tak");
			doZbioru = (doZbioruStr == "Tak");

			Maszyna NoweMaszyna;
			NoweMaszyna.setNazwa(nazwa);

			if (doUprawy)
				NoweMaszyna.setDoUprawy();

			if (doSiewu)
				NoweMaszyna.setDoSiewu();

			if (doNawozenia)
				NoweMaszyna.setDoNawozenia();

			if (doZbioru)
				NoweMaszyna.setDoZbioru();

			kolejka.push_back(NoweMaszyna);
		}

		plik.close();

		ParkMaszynowy = kolejka;
		std::cout << "Wczytywanie danych zakonczylo sie sukcesem" << std::endl;;
}

void Gospodarstwo::odczytajPolaZPliku(const char* sciezka)
{
		std::deque<Pole> pola;
		std::ifstream plik(sciezka);

		if (!plik)
		{
			std::cout << "B³¹d otwarcia pliku "<<sciezka << std::endl;
			return;
		}

		// Pomijamy nag³ówki kolumn
		std::string linia;
		std::string naglowek = "Nazwa;Powierzchnia[ha];Stadium Wzrostu;Uprawion;Nawieziono;Zasiano;Zebrano";
		std::getline(plik, linia);
		if (linia != naglowek) {
			plik.close();
			std::cout << "Plik " << sciezka << " nie zawiera poprawnie sformatowanych danych." << std::endl;
			return;
		}
		while (std::getline(plik, linia))
		{
			std::string nazwa, stadiumWzrostuStr, powierzchniaStr, uprawionoStr, nawiezionoStr, zasianoStr, zebranoStr;
			int stadiumWzrostu;
			float powierzchnia;
			bool uprawiono, nawieziono, zasiano, zebrano;

			std::stringstream ss(linia);
			std::getline(ss, nazwa, ';');
			std::getline(ss, powierzchniaStr, ';');
			std::getline(ss, stadiumWzrostuStr, ';');
			std::getline(ss, uprawionoStr, ';');
			std::getline(ss, nawiezionoStr, ';');
			std::getline(ss, zasianoStr, ';');
			std::getline(ss, zebranoStr, ';');

			powierzchnia = std::stof(powierzchniaStr);
			stadiumWzrostu = std::stoi(stadiumWzrostuStr);
			uprawiono = (uprawionoStr == "Tak");
			nawieziono = (nawiezionoStr == "Tak");
			zasiano = (zasianoStr == "Tak");
			zebrano = (zebranoStr == "Tak");

			Pole NowePole;
			NowePole.setNazwa(nazwa);
			NowePole.setPowierzchnia(powierzchnia);
			NowePole.setstadiumWzrostu(stadiumWzrostu);
			NowePole.setUprawiono(uprawiono);
			NowePole.setNawieziono(nawieziono);
			NowePole.setZasiano(zasiano);
			NowePole.setZebrano(zebrano);

			pola.push_back(NowePole);
		}

		plik.close();

		ZiemiaUprawna =  pola;

		std::cout << "Wczytywanie danych zakonczylo sie sukcesem" << std::endl;;
}
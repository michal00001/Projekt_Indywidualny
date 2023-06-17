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

void Gospodarstwo::zapiszMaszynyCSV(char* sciezka)
{
	std::cout << "Jak zrobisz drukarki to mnie odwiedz" << std::endl;
}

void Gospodarstwo::wyswietlListeMaszyn()
{
	std::unique_ptr<Drukarka> drukara = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	drukara->drukuj(ParkMaszynowy);
}

void Gospodarstwo::wyswietlListeMaszyn(int _ile)
{
	std::unique_ptr<Drukarka> drukara = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	//drukara->drukuj(ZiemiaUprawna);
}

void Gospodarstwo::wyswietlListePol()
{
	std::unique_ptr<Drukarka> drukara = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
	drukara->drukuj(ZiemiaUprawna);
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

void Gospodarstwo::edytujPole(std::deque<Pole>::iterator pole,std::string _nazwa,float _powierzchnia)
{
	pole->setNazwa(_nazwa);
	pole->setPowierzchnia(_powierzchnia);
}

void Gospodarstwo::usunPole(int _pozycja)
{
	auto iterator = ZiemiaUprawna.begin() + _pozycja;
	ZiemiaUprawna.erase(iterator);
}

void Gospodarstwo::zapiszPoleCSV(char* sciezka)
{
	/*std::unique_ptr<Drukarka> drukarka = DrukarkaFactory<CSVDrukarka>::stworzDrukarke();
	drukarka->drukuj(ZiemiaUprawna,sciezka);*/
}

std::deque<Maszyna>::iterator Gospodarstwo::getMaszyna(int _miejsce)
{
	std::deque<Maszyna>::iterator referencja ;
	referencja = ParkMaszynowy.begin();
	for (int i = 0; i < _miejsce; i++)
	{
		referencja++;
	}
	return referencja;
}

std::deque<Pole>::iterator Gospodarstwo::getPole(int _miejsce)
{
	std::deque<Pole>::iterator referencja;
	referencja = ZiemiaUprawna.begin();
	for (int i = 0; i < _miejsce; i++)
	{
		referencja++;
	}
	return referencja;
}

bool Gospodarstwo::czyParkMaszynowyPusty() const
{
	if (ParkMaszynowy.size() > 0)
		return false;
	else 
		return true;
}

bool Gospodarstwo::czyZiemiaUprawnaPusta() const
{
	if (ZiemiaUprawna.size() > 0)
		return false;
	else
		return true;
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

void Gospodarstwo::odczytajMaszynyZPliku(char* sciezka)
{
		std::ifstream plik(sciezka);
		if (!plik)
		{
			std::cout << "B³¹d otwarcia pliku." << std::endl;
			return;
		}

		std::deque<Maszyna> kolejka;

		// Pomijamy nag³ówki kolumn
		std::string linia;
		std::getline(plik, linia);

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

			Maszyna maszyna;
			maszyna.setNazwa(nazwa);

			if (doUprawy)
				maszyna.setDoUprawy();

			if (doSiewu)
				maszyna.setDoSiewu();

			if (doNawozenia)
				maszyna.setdDoNawozenia();

			if (doZbioru)
				maszyna.setDoZbioru();

			kolejka.push_back(maszyna);
		}

		plik.close();

		ParkMaszynowy = kolejka;
}

void Gospodarstwo::odczytajPolaZPliku(char* sciezka)
{
		std::deque<Pole> pola;
		std::ifstream plik(sciezka);

		if (!plik)
		{
			std::cout << "B³¹d otwarcia pliku." << std::endl;
			return;
		}

		std::string linia;
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
			uprawiono = (uprawionoStr == "1");
			nawieziono = (nawiezionoStr == "1");
			zasiano = (zasianoStr == "1");
			zebrano = (zebranoStr == "1");

			Pole pole;
			pole.setNazwa(nazwa);
			pole.setPowierzchnia(powierzchnia);
			pole.setstadiumWzrostu(stadiumWzrostu);
			pole.setUprawiono(uprawiono);
			pole.setNawieziono(nawieziono);
			pole.setZasiano(zasiano);
			pole.setZebrano(zebrano);

			pola.push_back(pole);
		}

		plik.close();

		ZiemiaUprawna =  pola;
}
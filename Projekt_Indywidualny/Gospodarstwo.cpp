#include "Gospodarstwo.h"

void Gospodarstwo::dodajMaszyne()
{
	using namespace std;
	bool warunek = true;
	while (warunek)
	{
		system("cls");
		int numerek = 1;
		cout << "Wybierz jedna z dostepnych klas maszyn lub opcje powrot"<<endl;
		cout << numerek << ". Kombajn" << endl; numerek++;
		cout << numerek << ". Kultywator" << endl; numerek++;
		cout << numerek << ". Rozsiewacz" << endl; numerek++;
		cout << numerek << ". Siewnik" << endl; numerek++;
		cout << numerek << ". Powrot" << endl;

		int x;
		while (1) { //nieskoñczona pêtla
			std::cin >> x; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cout << "Prosze podac liczbe z zakresu od 1 do " << numerek << std::endl; //komunikat o b³êdzie
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
		Maszyna pojazd;
		switch (x)
		{
		case 1:
			pojazd.setDoZbioru();
			break;
		case 2:
			pojazd.setDoUprawy();
			break;
		case 3:
			pojazd.setdDoNawozenia();
			break;
		case 4:
			pojazd.setDoSiewu();
			break;
		case 5:
			warunek = false;
			return;
		default:
			break;
		}
		if (sprawdzCzyNieWystepuje(pojazd)) {
			ParkMaszynowy.push_back(pojazd);
			warunek = false;
		}
		else {
			cout << "Podana maszyna juz wystêpuje na liscie"<<endl;
			system("cls");
		}
	}
}

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

void Gospodarstwo::dodajPole()
{

}

void Gospodarstwo::dodajPole(Pole _obiekt)
{
	if (sprawdzCzyNieWystepuje(_obiekt))
		ZiemiaUprawna.push_back(_obiekt);
}

void Gospodarstwo::usunPole(int _pozycja)
{
	auto iterator = ZiemiaUprawna.begin() + _pozycja;
	ZiemiaUprawna.erase(iterator);
}

Maszyna& Gospodarstwo::getMaszyna(int _miejsce)
{
	Maszyna pusta;
	// TODO: tu wstawiæ instrukcjê return
	return pusta;
}

Pole& Gospodarstwo::getPole(int _miejsce)
{
	Pole puste;
	return puste;
	// TODO: tu wstawiæ instrukcjê return
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
			return true;
	}
	return false;
}

void Gospodarstwo::wyczyscGospodarstwo()
{
	ZiemiaUprawna.clear();
	ParkMaszynowy.clear();
}

std::queue<Maszyna> Gospodarstwo::odczytajMaszynyZPliku(char* sciezka)
{
	{
		std::ifstream plik(sciezka);
		if (!plik.is_open()) {
			throw std::runtime_error("Nie mo¿na otworzyæ pliku.");
		}

		std::queue<Maszyna> kolejka;

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

			kolejka.push(maszyna);
		}

		plik.close();

		return kolejka;
	}
}

std::deque<Pole> Gospodarstwo::odczytajZPliku(const std::string& nazwaPliku)
{
		std::deque<Pole> pola;
		std::ifstream plik(nazwaPliku);

		if (!plik)
		{
			std::cout << "B³¹d otwarcia pliku." << std::endl;
			return pola;
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

		return pola;
}

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
	auto it = ParkMaszynowy.begin()+_pozycja;
	ParkMaszynowy.erase(it);
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
}

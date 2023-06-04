#include "Kalendarz.h"

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

	Kalendarz.push_back(temp);
}

void Kalendarz::dodajZabieg(Zabieg _obiekt)
{
	//if(_obiekt.poprawny)
	Kalendarz.push_back(_obiekt);
	//Kalendarz.sort();
}

void Kalendarz::dodajZabieg(char* _sciezka)
{
	std::fstream plik;
	char bufor[256] = { "\n" };//
	//std::string bufor;
	plik.open(_sciezka, std::ofstream::in);

	if (!plik.is_open())
		return; //blad 
	plik.getline(bufor, 256);
	if (strcmp(bufor, "Zapis danych") == 0)
	/*while (plik.good()) {
		;
	}*/

	plik.close();
}

void Kalendarz::wydrukujKalendarz()
{
	//naglowek tabelki
	using namespace std;
	cout.fill(' ');
	cout << "|" << std::setw(8) << "Data" << std::setw(6) << "|" << std::setw(14) << "Maszyna" << std::setw(10)
		<< "|" << std::setw(25) << "Pole" << std::setw(22) << "|" << std::endl;
	for (K_Iter  = Kalendarz.begin(); K_Iter != Kalendarz.end(); K_Iter++)
	{
		std::cout << *K_Iter << std::endl;
	}
}

void Kalendarz::wydrukujKalendarz(char* _sciezka)
{
	std::fstream plik;
	plik.open(_sciezka, std::ofstream::out);
	if (!plik.is_open())
		return;//blad
	plik << "Zapis danych\n";
	plik.fill(' ');
	plik << "|" << std::setw(8) << "Data" << std::setw(6) << "|" << std::setw(14) << "Maszyna" << std::setw(10) 
		<< "|" << std::setw(25) << "Pole" << std::setw(22) << "|" << std::endl;
	for (K_Iter = Kalendarz.begin(); K_Iter != Kalendarz.end(); K_Iter++)
	{
		plik << *K_Iter << std::endl;
	}
	plik.close();
}

void Kalendarz::wydrukujKalendarz(char* _sciezka,bool _csv)
{
	std::fstream plik;
	plik.open(_sciezka, std::ofstream::out);
	if (!plik.is_open())
		return;//blad
	plik << "Zapis danych\n";
	plik.fill(' ');
	plik << "|" << std::setw(8) << "Data" << std::setw(6) << "|" << std::setw(14) << "Maszyna" << std::setw(10)
		<< "|" << std::setw(25) << "Pole" << std::setw(22) << "|" << std::endl;
	for (K_Iter = Kalendarz.begin(); K_Iter != Kalendarz.end(); K_Iter++)
	{
		plik << *K_Iter << std::endl;
	}
	plik.close();
}

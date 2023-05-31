#include "Kalendarz.h"

std::ostream& operator<<(std::ostream& out, Zabieg& obiekt) {
	out << obiekt.getData() << ";" << obiekt.getMaszyna() << ";" << obiekt.getPole() << std::endl;
	return out;
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

	Kalendarz.push_back(temp);
}

void Kalendarz::dodajZabieg(char* _sciezka)
{
	std::fstream plik;
	//char bufor[256] = { "\n" };//
	std::string bufor;
	plik.open(_sciezka, std::ofstream::in);

	if (!plik.is_open())
		return; //blad 
	while (plik.good()) {
		std::getline(plik,bufor, plik.widen('\n'));
	}

	plik.close();
}

void Kalendarz::wydrukujKalendarz()
{
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
	for (K_Iter = Kalendarz.begin(); K_Iter != Kalendarz.end(); K_Iter++)
	{
		plik << *K_Iter << std::endl;
	}
	plik.close();
}

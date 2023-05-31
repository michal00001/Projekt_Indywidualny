#include "Kalendarz.h"

std::ostream& operator<<(std::ostream& out, Zabieg& obiekt) {
	out/* << obiekt.getData()*/ << " " << obiekt.getMaszyna() << " " << obiekt.getPole() << std::endl;
	return out;
}

void Kalendarz::dodajZabieg()
{
	Zabieg temp;

	std::cout << "Podaj dzien, miesiac i rok" << std::endl;
	int dzie, mies, rok,klasa;
	std::cin >> dzie >> mies >> rok;
	//temp.setData(dzie,mies,rok);

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

void Kalendarz::wydrukujKalendarz()
{
	for (K_Iter  = Kalendarz.begin(); K_Iter != Kalendarz.end(); K_Iter++)
	{
		std::cout << *K_Iter << std::endl;
	}
}

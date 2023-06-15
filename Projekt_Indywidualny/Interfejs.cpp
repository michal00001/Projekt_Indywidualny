#include "Interfejs.h"

void Interfejs::MenuGlowne()
{
	using namespace std;
	bool warunek = true;

	while (warunek) {
		system("cls");
		cout << "Menu glowne\nKalendarz zabiegow agrotechnicznych" << endl;
		cout << "1. Wejdz w kalendarz zabiegow" << endl;
		cout << "2. Wejdz w zapisane pola" << endl;
		cout << "3. Wejdz w zapisane maszyny" << endl;
		cout << "4. Wyjdz z programu" << endl;
		int x;
		while (1) { //niesko�czona p�tla
			std::cin >> x; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b��du
				std::cout << "Prosze podac liczb� z zakresu od 1 do 4" << endl; //komunikat o b��dzie
				std::cin.clear(); //resetowanie flag b��du
				std::cin.ignore(256, '\n'); //czyszczenie 256 znak�w bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
			switch (x)
			{
				case 1:
					OpcjaKalendarzZabiegow();
					break;
				case 2:
					OpcjaZapisanePola();
					break;
				case 3:
					OpcjaZapisaneMaszyny();
					break;
				case 4:
					KalendarzZabiegow.wyczyscListeZabiegow();
					Gospodarstwo.wyczyscGospodarstwo();
					warunek = false;
					break;
				default:
					cout << "Prosze podac wartosc z zakresu od 1 do 4"<<endl;
					system("pause");
			}
	}
}

void Interfejs::OpcjaKalendarzZabiegow()
{
	using namespace std;
	bool warunek = true;
	std::unique_ptr<Drukarka> drukarka;
	while (warunek) {
		system("cls");
		int numerek = 1;
		//wyswietl 5 pierwszych zabiegow
		cout<< "Menu Kalendarz Zabiegow Agrotechnicznych" << endl;
		cout << numerek << ". Dodaj zabieg" << endl; numerek++;
		cout << numerek << ". Usun wybrany zabieg" << endl; numerek++;
		cout << numerek << ". Edytuj wybrany zabieg" << endl; numerek++;
		cout << numerek << ". Wczytaj kalendarz z pliku .CSV" << endl; numerek++;
		cout << numerek << ". Wyswietl caly kalendarz na terminalu" << endl; numerek++;
		cout << numerek << ". Zapisz jako plik .CSV" << endl; numerek++;
		cout << numerek << ". Zapisz jako plik .txt" << endl; numerek++;
		cout << numerek << ". Powrot" << endl;
		int x;
		while (1) { //niesko�czona p�tla
			std::cin >> x; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b��du
				std::cout << "Prosze podac liczb� z zakresu od 1 do "<<numerek << std::endl; //komunikat o b��dzie
				std::cin.clear(); //resetowanie flag b��du
				std::cin.ignore(256, '\n'); //czyszczenie 256 znak�w bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
		switch (x)
		{
		case 1:
			OpcjaDodaj(1);
			break;
		case 2:
			OpcjaUsun(1);
			break;
		case 3:
			OpcjaEdytuj(1);
			break;
		case 4:
			OpcjaWczytaj();
			break;
		case 5:
			//wyswietl terminal
			drukarka = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
			if (!KalendarzZabiegow.czyListaPusta())
				drukarka->drukuj(KalendarzZabiegow.getlistaZabiegow());
			else
				cout << "Kalendarz jest pusty" << endl;
			system("pause");
			break;
		case 6:
			//zapis .csv
			drukarka = DrukarkaFactory<CsvDrukarka>::stworzDrukarke();
			if (!KalendarzZabiegow.czyListaPusta())
				drukarka->drukuj(KalendarzZabiegow.getlistaZabiegow()); 
			else
				cout << "Kalendarz jest pusty" << endl;
			system("pause");
			break;
		case 7:
			//zapis .txt
			drukarka = DrukarkaFactory<TxtDrukarka>::stworzDrukarke();
			if (!KalendarzZabiegow.czyListaPusta())
				drukarka->drukuj(KalendarzZabiegow.getlistaZabiegow()); 
			else
				cout << "Kalendarz jest pusty" << endl;
			system("pause");
			break;
		case 8:
			warunek = false;
			break;
		default:
			cout << "Prosze podac liczb� z zakresu od 1 do " << numerek << endl;
			system("pause");
		}
	}
}

void Interfejs::OpcjaZapisanePola()
{
	using namespace std;
	bool warunek = true;
	std::unique_ptr<Drukarka> drukarka;
	while (warunek) {
		system("cls");
		int numerek = 1;
		//wyswietl 5 pierwszych p�l wg nazwy
		cout << "Menu Katalog Pol" << endl;
		cout << numerek << ". Dodaj element" << endl; numerek++;
		cout << numerek << ". Usun wybrany element" << endl; numerek++;
		cout << numerek << ". Edytuj wybrany element" << endl; numerek++;
		cout << numerek << ". Wczytaj dane z pliku .CSV" << endl; numerek++;
		cout << numerek << ". Wyswietl caly zbior na terminalu" << endl; numerek++;
		cout << numerek << ". Zapisz jako plik .CSV" << endl; numerek++;
		cout << numerek << ". Zapisz jako plik .txt" << endl; numerek++;
		cout << numerek << ". Powrot" << endl;
		int x;
		while (1) { //niesko�czona p�tla
			std::cin >> x; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b��du
				std::cout << "Prosze podac liczb� z zakresu od 1 do " << numerek << std::endl; //komunikat o b��dzie
				std::cin.clear(); //resetowanie flag b��du
				std::cin.ignore(256, '\n'); //czyszczenie 256 znak�w bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
		switch (x)
		{
		case 1:
			OpcjaDodaj(2);
			break;
		case 2:
			OpcjaUsun(2);
			break;
		case 3:
			OpcjaEdytuj(2);
			break;
		case 4:
			
			break;
		case 5:
			//wyswietl terminal
			
			break;
		case 6:
			//zapis .csv
			
			break;
		case 7:
			//zapis .txt
			
			break;
		case 8:
			warunek = false;
			break;
		default:
			cout << "Prosze podac liczb� z zakresu od 1 do " << numerek << endl;
			system("pause");
		}
	}
}

void Interfejs::OpcjaZapisaneMaszyny()
{
	using namespace std;
	bool warunek = true;
	std::unique_ptr<Drukarka> drukarka;
	while (warunek) {
		system("cls");
		int numerek = 1;
		//wyswietl 5 pierwszych p�l wg nazwy
		cout << "Menu Katalog Maszyn" << endl;
		cout << numerek << ". Dodaj element" << endl; numerek++;
		cout << numerek << ". Usun wybrany element" << endl; numerek++;
		cout << numerek << ". Edytuj wybrany element" << endl; numerek++;
		cout << numerek << ". Wczytaj dane z pliku .CSV" << endl; numerek++;
		cout << numerek << ". Wyswietl caly zbior na terminalu" << endl; numerek++;
		cout << numerek << ". Zapisz jako plik .CSV" << endl; numerek++;
		cout << numerek << ". Zapisz jako plik .txt" << endl; numerek++;
		cout << numerek << ". Powrot" << endl;
		int x;
		while (1) { //niesko�czona p�tla
			std::cin >> x; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b��du
				std::cout << "Prosze podac liczb� z zakresu od 1 do " << numerek << std::endl; //komunikat o b��dzie
				std::cin.clear(); //resetowanie flag b��du
				std::cin.ignore(256, '\n'); //czyszczenie 256 znak�w bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
		switch (x)
		{
		case 1:
			OpcjaDodaj(3);
			break;
		case 2:
			OpcjaUsun(3);
			break;
		case 3:
			OpcjaEdytuj(3);
			break;
		case 4:

			break;
		case 5:
			//wyswietl terminal

			break;
		case 6:
			//zapis .csv

			break;
		case 7:
			//zapis .txt

			break;
		case 8:
			warunek = false;
			break;
		default:
			cout << "Prosze podac liczb� z zakresu od 1 do " << numerek << endl;
			system("pause");
		}
	}
}

void Interfejs::OpcjaDodaj(int _opcja)
{
	switch (_opcja) {
	case 1:
		KalendarzZabiegow.dodajZabieg();
		break;
	case 2:
		Gospodarstwo.dodajPole();
		break;
	case 3:
		Gospodarstwo.dodajMaszyne();
		break;
	}
}

void Interfejs::OpcjaUsun(int _opcja)
{
	int pozycja = -1;
	bool warunekWhile = true;
	while (warunekWhile) {
		system("cls");
		switch (_opcja)	{
		case 1:
			//wyswietl zabiegi
			break;
		case 2:
			//wyswietl pola
			break;
		case 3:
			//wyswietl maszyny
			break;
		}
		std::cout << "Prosze podac numer elementu do usuniecia" << std::endl;
		while (1) { //niesko�czona p�tla
			std::cin >> pozycja; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b��du
				std::cout << "Prosze podac liczb�"<< std::endl; //komunikat o b��dzie
				std::cin.clear(); //resetowanie flag b��du
				std::cin.ignore(256, '\n'); //czyszczenie 256 znak�w bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}

		if (pozycja < 0 || czyPozaZakresem(_opcja, pozycja))
		{
			std::cout << "Podano wartosc poza zakresem tablicy" << std::endl;
			system("pause");
		}
		else
			warunekWhile = false;
	}

	switch (_opcja) {
	case 1:
		KalendarzZabiegow.usunZabieg(pozycja);
		break;
	case 2:
		Gospodarstwo.usunPole(pozycja);
		break;
	case 3:
		Gospodarstwo.usunMaszyne(pozycja);
		break;
	}
}

void Interfejs::OpcjaEdytuj(int _opcja)
{
	switch (_opcja) {
	case 1:
		//KalendarzZabiegow.edytujZabieg();
		break;
	case 2:
		//Gospodarstwo.edytujPole();
		break;
	case 3:
		//Gospodarstwo.edytujMaszyne();
		break;
	}
}

void Interfejs::OpcjaWczytaj()
{

}

bool Interfejs::czyPozaZakresem(int _opcja, int _indeksTablicy)
{
	switch (_opcja) {
	case 1:
		if (KalendarzZabiegow.getlistaZabiegow().size() >= _indeksTablicy)
		{
			return true;
		}
		break;
	case 2:
		if (KalendarzZabiegow.getlistaZabiegow().size() >= _indeksTablicy)
		{
			return true;
		}
		break;
	case 3:
		if (KalendarzZabiegow.getlistaZabiegow().size() >= _indeksTablicy)
		{
			return true;
		}
		break;
	}
	return false;
}

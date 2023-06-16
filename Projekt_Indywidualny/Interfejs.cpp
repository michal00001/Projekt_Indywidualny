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

		cout << "Menu kalendarza zabiegow" << endl;
		if (KalendarzZabiegow.getsizelistaZabiegowa()) {
			//wyswietl 5 pierwszych zabiegow
			drukarka = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
			//drukarka->drukuj(KalendarzZabiegow.getlistaZabiegow(), 5);
		}
		switch (MenuWyboru(numerek))
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
			OpcjaWczytaj(1);
			break;
		case 5:
			//wyswietl terminal
			drukarka = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
			if (!KalendarzZabiegow.czyListaPusta());
				//drukarka->drukuj(KalendarzZabiegow.getlistaZabiegow());
			else
				cout << "Kalendarz jest pusty" << endl;
			system("pause");
			break;
		case 6:
			//zapis .csv
		//	drukarka = DrukarkaFactory<CsvDrukarka>::stworzDrukarke();
		//	drukarka->drukuj(KalendarzZabiegow.getlistaZabiegow());
			system("pause");
			break;
		case 7:
			//zapis .txt
		//	drukarka = DrukarkaFactory<TxtDrukarka>::stworzDrukarke();
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
	while (warunek) {
		system("cls");
		int numerek = 1;
		
		cout << "Menu Katalog Pol" << endl;
		
		//wyswietl 5 pierwszych p�l wg nazwy
		try {
		Gospodarstwo.wyswietlListePol(5);
		}
		catch (domain_error e) {
			cerr << e.what() << endl;
		}
		switch (MenuWyboru(numerek))
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
			OpcjaWczytaj(2);
			break;
		case 5:
			//wyswietl terminal
			Gospodarstwo.wyswietlListePol();
			system("pause");
			break;
		case 6:
			//zapis .csv
			Gospodarstwo.zapiszCSV();
			break;
		case 7:
			//zapis .txt
			//Gospodarstwo.zapiszTXT();
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
		
	
		cout << "Menu Katalog Maszyn" << endl;
		//wyswietl 5 pierwszych p�l wg nazwy
		
		switch (MenuWyboru(numerek))
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
	Pole temp;
	switch (_opcja) {
	case 1:
		//KalendarzZabiegow.dodajZabieg();
		break;
	case 2:
		temp.wprowadzDane();
		Gospodarstwo.dodajPole(temp);
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
		try {
			switch (_opcja) {
			case 1:
				//wyswietl zabiegi
				//KalendarzZabiegow.wyswietlListaZabiegow();
				break;
			case 2:
				//wyswietl pola
				Gospodarstwo.wyswietlListePol();
				break;
			case 3:
				//wyswietl maszyny
				Gospodarstwo.wyswietlListeMaszyn();
				break;
			}
		}
		catch (std::domain_error e) {
			std::cerr << e.what()<<std::endl;
			system("pause");
			return;
		}
		
		cout << "Prosze podac numer elementu do usuniecia" << endl;
		while (1) { //niesko�czona p�tla
			cin >> pozycja; //pobranie zmiennej
			if (cin.fail() == true) { //wykrycie b��du
				cout << "Prosze podac liczb�"<< endl; //komunikat o b��dzie
				cin.clear(); //resetowanie flag b��du
				cin.ignore(256, '\n'); //czyszczenie 256 znak�w bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}

		if (pozycja < 0 || czyPozaZakresem(_opcja, pozycja))
		{
			cout << "Podano wartosc poza zakresem tablicy" << endl;
			system("pause");
		}
		else
			warunekWhile = false;
	}

	switch (_opcja) {
	case 1:
		//KalendarzZabiegow.usunZabieg(pozycja);
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

void Interfejs::OpcjaWczytaj(int _opcja)
{
	char sciezka[] = "Pliczek.txt";
	switch (_opcja) {
	case 1:
		KalendarzZabiegow.odczytajZabiegZPliku(sciezka);
		break;
	case 2:
		Gospodarstwo.odczytajMaszynyZPliku(sciezka);
		break;
	case 3:
		Gospodarstwo.odczytajMaszynyZPliku(sciezka);
		break;
	}
}

int Interfejs::MenuWyboru(int& numerek)

{
	using namespace std;
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
			std::cout << "Prosze podac liczbe z zakresu od 1 do " << numerek << std::endl; //komunikat o b��dzie
			std::cin.clear(); //resetowanie flag b��du
			std::cin.ignore(256, '\n'); //czyszczenie 256 znak�w bufora
		} //lub do napotkania znaku nowej linii
		else break;
	}
	return x;
}

bool Interfejs::czyPozaZakresem(int _opcja, int _indeksTablicy)
{
	switch (_opcja) {
	case 1:
		if (KalendarzZabiegow.getsizelistaZabiegowa() >= _indeksTablicy)
		{
			return false;
		}
		break;
	case 2:
		if (Gospodarstwo.getSizeZiemiaUprawna() >= _indeksTablicy)
		{
			return false;
		}
		break;
	case 3:
		if (Gospodarstwo.getSizeParkMaszynowy() >= _indeksTablicy)
		{
			return false;
		}
		break;
	}
	return true;
}

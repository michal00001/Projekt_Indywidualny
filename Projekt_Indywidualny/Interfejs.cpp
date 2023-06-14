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
		while (1) { //nieskoñczona pêtla
			std::cin >> x; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cout << "Prosze podac inta" << std::endl; //komunikat o b³êdzie
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
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
		while (1) { //nieskoñczona pêtla
			std::cin >> x; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cout << "Prosze podac liczbê z wartoœci od 1 do"<<numerek << std::endl; //komunikat o b³êdzie
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
		switch (x)
		{
		case 1:
			OpcjaDodaj();
			break;
		case 2:
			OpcjaUsun();
			break;
		case 3:
			OpcjaEdytuj();
			break;
		case 4:
			OpcjaWczytajKalendarz();
			break;
		case 5:
			//wyswietl terminal
			drukarka = DrukarkaFactory<TerminalDrukarka>::stworzDrukarke();
			if(!KalendarzZabiegow.czyListaPusta())
				drukarka->drukuj(KalendarzZabiegow.getlistaZabiegow());
			break;
		case 6:
			//zapis .csv
			drukarka = DrukarkaFactory<CsvDrukarka>::stworzDrukarke();
			if (!KalendarzZabiegow.czyListaPusta())
				drukarka->drukuj(KalendarzZabiegow.getlistaZabiegow());
			break;
		case 7:
			//zapis .txt
			drukarka = DrukarkaFactory<TxtDrukarka>::stworzDrukarke();
			if (!KalendarzZabiegow.czyListaPusta())
				drukarka->drukuj(KalendarzZabiegow.getlistaZabiegow());
			break;
		case 8:
			warunek = false;
			break;
		default:
			cout << "Prosze podac wartosc z zakresu od 1 do 7" << endl;
			system("pause");
		}
	}
}

void Interfejs::OpcjaZapisanePola()
{
}

void Interfejs::OpcjaZapisaneMaszyny()
{
}

void Interfejs::OpcjaDodajZabieg()
{
	KalendarzZabiegow.dodajZabieg();
}

void Interfejs::OpcjaUsunZabieg()
{

}

void Interfejs::OpcjaWczytajKalendarz()
{
}

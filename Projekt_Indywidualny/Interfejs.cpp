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
		
			switch (podajOpcje(1,4))
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

		cout << "Menu kalendarza zabiegow\n"<< endl;
	
			//wyswietl 5 pierwszych zabiegow
		try {
			KalendarzZabiegow.wyswietlListeZabiegow(5);
		}
		catch (domain_error e) {
			cerr << e.what() << endl;
		}
		cout << "\n";
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
			system("cls");
			try {
				KalendarzZabiegow.wyswietlListeZabiegow(5);
			}
			catch (domain_error e) {
				cerr << e.what() << endl;
			}
			system("pause");
			break;
		case 6:
			//zapis .csv
			try {
				//KalendarzZabiegow.ZapiszZabiegiCSV();
			}
			catch (domain_error e) {
				cerr << e.what() << endl;
			}
			break;
		case 7:
			//zapis .txt
			try {
				//KalendarzZabiegow.wyswietlListeZabiegow(5);
			}
			catch (domain_error e) {
				cerr << e.what() << endl;
			}
			break;
		case 8:
			warunek = false;
			break;
		default:
			cout << "Prosze podac liczbê z zakresu od 1 do " << numerek << endl;
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
		
		cout << "Menu Katalog Pol\n" << endl;
		
		//wyswietl 5 pierwszych pól
		try {
		Gospodarstwo.wyswietlListePol(5);
		}
		catch (domain_error e) {
			cerr << e.what() << endl;
		}
		cout << "\n";
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
			system("cls");
			try {
				Gospodarstwo.wyswietlListePol();
			}
			catch (domain_error e) {
				std::cerr << e.what() << std::endl;
			}
			system("pause");
			break;
		case 6:
			//zapis .csv
			system("cls");
			try {
				//Gospodarstwo.zapiszPoleCSV();
			}
			catch (domain_error e) {
				cerr << e.what() << endl;
			}
			break;
		case 7:
			//zapis .txt
			//Gospodarstwo.zapiszTXT();
			break;

		case 8:
			warunek = false;
			break;
		default:
			cout << "Prosze podac liczbê z zakresu od 1 do " << numerek << endl;
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
		//wyswietl 5 pierwszych maszyn
		try {
			Gospodarstwo.wyswietlListeMaszyn();
		}
		catch (domain_error e) {
			cerr << e.what() << endl;
		}
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
			system("cls");
			std::cout << "In developement" << std::endl;
			system("pause");
			break;
		case 5:
			//wyswietl terminal
			system("cls");
			try {
				Gospodarstwo.wyswietlListeMaszyn();
			}
			catch (domain_error e) {
				cerr << e.what() << endl;
			}
			system("pause");
			break;
		case 6:
			//zapis .csv
			system("cls");
			std::cout << "In developement" << std::endl;
			system("pause");
			break;
		case 7:
			//zapis .txt
			system("cls");
			std::cout << "In developement" << std::endl;
			system("pause");
			break;
		case 8:
			warunek = false;
			break;
		default:
			cout << "Prosze podac liczbê z zakresu od 1 do " << numerek << endl;
			system("pause");
		}
	}
}

void Interfejs::OpcjaDodaj(int _opcja)
{
	Pole temp;
	switch (_opcja) {
	case 1:
		dodawanieZabiegow();
		break;
	case 2:
		dodawaniePol();
		break;
	case 3:
		dodawanieMaszyn();
		break;
	}
}

void Interfejs::OpcjaUsun(int _opcja)
{

	int pozycja = -1;
	int size = 0;
	bool warunekWhile = true;
	while (warunekWhile) {
		system("cls");
		cout << "Menu usuwania\n" << endl;
		try {
			switch (_opcja) {
			case 1:
				//wyswietl zabiegi
				KalendarzZabiegow.wyswietlListeZabiegow();
				size = (int)KalendarzZabiegow.getsizelistaZabiegowa();
				break;
			case 2:
				//wyswietl pola
				Gospodarstwo.wyswietlListePol();
				size = (int)Gospodarstwo.getSizeZiemiaUprawna();
				break;
			case 3:
				//wyswietl maszyny
				Gospodarstwo.wyswietlListeMaszyn();
				size = (int)Gospodarstwo.getSizeParkMaszynowy();
				break;
			}
		}
		catch (std::domain_error e) {
			std::cerr << e.what()<<std::endl;
			system("pause");
			return;
		}
		cout <<"\nPodaj element ktory chcesz usunac" << endl;
		pozycja = podajOpcje(1,size);
		pozycja--;
		if (czyPozaZakresem(_opcja, pozycja))
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
	int pozycja = -1;
	int size = 0;
	bool warunekWhile = true;
	while (warunekWhile) {
		system("cls");
		cout << "Menu edycji\n" << endl;
		try {
			switch (_opcja) {
			case 1:
				//wyswietl zabiegi
				KalendarzZabiegow.wyswietlListeZabiegow();
				size = (int)KalendarzZabiegow.getsizelistaZabiegowa();
				break;
			case 2:
				//wyswietl pola
				Gospodarstwo.wyswietlListePol();
				size = (int)Gospodarstwo.getSizeZiemiaUprawna();
				break;
			case 3:
				//wyswietl maszyny
				Gospodarstwo.wyswietlListeMaszyn();
				size = (int)Gospodarstwo.getSizeParkMaszynowy();
				break;
			}
		}
		catch (std::domain_error e) {
			std::cerr << e.what() << std::endl;
			system("pause");
			return;
		}
		cout << "\nPodaj element ktory chcesz edytowac" << endl;
		pozycja = podajOpcje(1, size);
		pozycja--;
		if (czyPozaZakresem(_opcja, pozycja))
		{
			cout << "Podano wartosc poza zakresem tablicy" << endl;
			system("pause");
		}
		else
			warunekWhile = false;
	}

	switch (_opcja) {
	case 1:
		//KalendarzZabiegow.edytujZabieg();
		break;
	case 2:
		system("cls");
		try {
			edycjaPol(Gospodarstwo.getPole(pozycja));
		}
		catch(out_of_range const& exc){
			cerr << exc.what() << endl;
		}
		break;
	case 3:
		system("cls");
		cout << "W obecnej wersji maszyn nie da siê edytowac" << endl;
		system("pause");
		//Gospodarstwo.edytujMaszyne();
		break;
	}
}

void Interfejs::OpcjaWczytaj(int _opcja)
{
	char sciezka[] = "Pliczek.txt";
	switch (_opcja) {
	case 1:
		//KalendarzZabiegow.odczytajZabiegZPliku(sciezka);
		break;
	case 2:
		Gospodarstwo.odczytajMaszynyZPliku(sciezka);
		break;
	case 3:
		Gospodarstwo.odczytajMaszynyZPliku(sciezka);
		break;
	}
}

int Interfejs::podajOpcje(int _od, int _do) {
	while (1) {
		int x;
		while (1) { //nieskoñczona pêtla
			std::cin >> x; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cout << "Prosze podac liczbe z zakresu od " << _od << " do " << _do << std::endl; //komunikat o b³êdzie
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
		if (x >= _od && x <= _do)
			return x;
		else
			std::cout << "Prosze podac liczbe z zakresu od " << _od << " do " << _do << std::endl; //komunikat o b³êdzie
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
	
	return podajOpcje(1,numerek);
}

bool Interfejs::czyPozaZakresem(int _opcja, int _indeksTablicy)
{
	if (_indeksTablicy < 0) return true;
	switch (_opcja) {
	case 1:
		if (_indeksTablicy >= KalendarzZabiegow.getsizelistaZabiegowa())
		{
			return true;
		}
		break;
	case 2:
		if (_indeksTablicy >= Gospodarstwo.getSizeZiemiaUprawna())
		{
			return true;
		}
		break;
	case 3:
		if (_indeksTablicy >= Gospodarstwo.getSizeParkMaszynowy())
		{
			return true;
		}
		break;
	}
	return false;
}

void Interfejs::dodawaniePol()
{
	Gospodarstwo.dodajPole(wprowadzDane());
}

void Interfejs::dodawanieZabiegow()
{

}

void Interfejs::dodawanieMaszyn()
{
	using namespace std;
	bool warunek = true;
	while (warunek)
	{
		system("cls");
		int numerek = 1;
		cout << "Wybierz jedna z dostepnych klas maszyn lub opcje powrot" << endl;
		cout << numerek << ". Kombajn" << endl; numerek++;
		cout << numerek << ". Kultywator" << endl; numerek++;
		cout << numerek << ". Rozsiewacz" << endl; numerek++;
		cout << numerek << ". Siewnik" << endl; numerek++;
		cout << numerek << ". Powrot" << endl;

		Maszyna pojazd;

		switch (podajOpcje(1, numerek))
		{
		case 1:
			pojazd.setDoZbioru();
			break;
		case 2:
			pojazd.setDoUprawy();
			break;
		case 3:
			pojazd.setDoNawozenia();
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
		if (Gospodarstwo.sprawdzCzyNieWystepuje(pojazd)) {
			Gospodarstwo.dodajMaszyne(pojazd);
			warunek = false;
		}
		else {
			cout << "Podana maszyna juz wystêpuje na liscie" << endl;
			system("pause");
			system("cls");
		}
	}
}

void Interfejs::edycjaPol(Pole& _pole)
{
	std::string nowaNazwa;
	float nowaPowierzchnia;
	std::cout << "Wybierz element ktory chcesz edytowac:" << std::endl;
	std::cout << "1.Nazwa:" << _pole.getNazwa() << "\n" << "2.Powierzchnia pola[ha]:" << _pole.getPowierzchnia()
		<< "\n" << "3.Opcja resetowania powierzchnia pola" << std::endl;
	std::cout<<"4.Powrot" << std::endl;
	switch (podajOpcje(1,3))
	{
	case 1:
		std::cin >> nowaNazwa;
		_pole.setNazwa(nowaNazwa);
		break;
	case 2:
		std::cin >> nowaPowierzchnia;
		_pole.setPowierzchnia(nowaPowierzchnia);
		break;
	case 3:
		_pole.wyzerujStanPola();
		break;
	case 4:
	default:
		break;
	}
}

Pole Interfejs::wprowadzDane()
{
	using namespace std;
	string _nazwa;
	float _powierzchnia=0.0;
	bool warunekWhile = true;
	Pole nowePole;
	system("cls");

	getline(cin, _nazwa);
	cout << "Podaj nazwe pola: " << endl;
	getline(cin, _nazwa);

	while (_powierzchnia <= 0) {
		system("cls");
		cout << "Podana nazwa pola to " << _nazwa << endl;
		cout << "Podaj powierzchnie pola: " << endl;
		while (1) { //nieskoñczona pêtla
			cin >> _powierzchnia; //pobranie zmiennej
			if (cin.fail() == true || _powierzchnia <= 0) { //wykrycie b³êdu
				cout << "Prosze podac poprawna wartosc" << endl; //komunikat o b³êdzie
				cin.clear(); //resetowanie flag b³êdu
				cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
	}

	nowePole.setNazwa(_nazwa);
	nowePole.setPowierzchnia(_powierzchnia);

	return nowePole;
}
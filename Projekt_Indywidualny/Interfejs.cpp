#include "Interfejs.h"

using namespace std;

void Interfejs::MenuGlowne()
{
	
	bool warunek = true;

	while (warunek) {
		system("cls");
		cout << "Menu glowne\nKalendarz zabiegow agrotechnicznych" << endl;
		cout << "1. Wejdz w kalendarz zabiegow" << endl;
		cout << "2. Wejdz w zapisane pola" << endl;
		cout << "3. Wejdz w zapisane maszyny" << endl;
		cout << "4. Wyjdz z programu" << endl;
		
			switch (bezpiecznyInt(1,4))
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
	bool warunek = true;
	
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
			break;
		case 6:
			//zapis .csv
			try {
				string sciezka = podajSciezke(".csv");
				KalendarzZabiegow.ZapiszZabiegiCSV(sciezka.c_str());
			}
			catch (domain_error e) {
				cerr << e.what() << endl;
			}
			break;
		case 7:
			//zapis .txt
			cout << "In developement";
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
		}
			system("pause");
	}
}

void Interfejs::OpcjaZapisanePola()
{
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
				cerr << e.what() << endl;
			}
			
			break;
		case 6:
			//zapis .csv
			system("cls");
			try {
				string sciezka = podajSciezke(".csv");
				Gospodarstwo.zapiszPoleCSV(sciezka.c_str());
			}
			catch (domain_error e) {
				cerr << e.what() << endl;
			}
			system("pause");
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
	bool warunek = true;
	unique_ptr<Drukarka> drukarka;
	while (warunek) {
		system("cls");
		int numerek = 1;
		
	
		cout << "Menu Katalog Maszyn\n" << endl;
		//wyswietl 5 pierwszych maszyn
		try {
			Gospodarstwo.wyswietlListeMaszyn();
		}
		catch (domain_error e) {
			cerr << e.what() << endl;
		}
		cout << "\n" << endl;
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
			OpcjaWczytaj(3);
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
			try {
				string sciezka = podajSciezke(".csv");
				Gospodarstwo.zapiszMaszynyCSV(sciezka.c_str());
			}
			catch (domain_error e) {
				cerr << e.what() << endl;
			}
			system("pause");
			break;
		case 7:
			//zapis .txt
			system("cls");
			cout << "In developement" << endl;
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
	system("cls");
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
		catch (domain_error e) {
			cerr << e.what()<<endl;
			system("pause");
			return;
		}
		cout <<"\nPodaj element ktory chcesz usunac" << endl;
		pozycja = bezpiecznyInt(1,size);
		pozycja--;
		if (czyPozaZakresem(_opcja, pozycja))
		{
			cout << "Podano wartosc poza zakresem tablicy" << endl;
			system("pause");
		}
		else
			warunekWhile = false;
	}

	system("cls");
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
	system("pause");
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
		catch (domain_error e) {
			cerr << e.what() << endl;
			system("pause");
			return;
		}
		cout << "\nPodaj element ktory chcesz edytowac" << endl;
		pozycja = bezpiecznyInt(1, size);
		pozycja--;
		if (czyPozaZakresem(_opcja, pozycja))
		{
			cout << "Podano wartosc poza zakresem tablicy" << endl;
			system("pause");
		}
		else
			warunekWhile = false;
	}

	system("cls");
	switch (_opcja) {
	case 1:
		
		edycjaZabiegow(KalendarzZabiegow.getZabieg(pozycja));
		break;
	case 2:
		try {
			edycjaPol(Gospodarstwo.getPole(pozycja));
		}
		catch(out_of_range const& exc){
			cerr << exc.what() << endl;
		}
		break;
	case 3:
		cout << "W obecnej wersji maszyn nie da siê edytowac" << endl;
		//Gospodarstwo.edytujMaszyne();
		break;
	}
	system("pause");

}

void Interfejs::OpcjaWczytaj(int _opcja)
{
	string sciezka = podajSciezke(".csv");
	system("cls");
	switch (_opcja) {
	case 1:
		KalendarzZabiegow.odczytajZabiegZPliku(sciezka.c_str());
		break;
	case 2:
		Gospodarstwo.odczytajPolaZPliku(sciezka.c_str());
		break;
	case 3:
		Gospodarstwo.odczytajMaszynyZPliku(sciezka.c_str());
		break;
	}
	system("pause");
}

int Interfejs::bezpiecznyInt(int _od, int _do) {
	while (1) {
		int x;
		while (1) { //nieskoñczona pêtla
			cin >> x; //pobranie zmiennej
			if (cin.fail() == true) { //wykrycie b³êdu
				cout << "Prosze podac liczbe z zakresu od " << _od << " do " << _do << endl; //komunikat o b³êdzie
				cin.clear(); //resetowanie flag b³êdu
				cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
		if (x >= _od && x <= _do)
			return x;
		else
			cout << "Prosze podac liczbe z zakresu od " << _od << " do " << _do << endl; //komunikat o b³êdzie
	}
}

float Interfejs::bezpiecznyFloat(float _od, float _do)
{
	while (1) {
		float x;
		while (1) { //nieskoñczona pêtla
			cin >> x; //pobranie zmiennej
			if (cin.fail() == true) { //wykrycie b³êdu
				cout << "Prosze podac liczbe z zakresu od " << _od << " do " << _do << endl; //komunikat o b³êdzie
				cin.clear(); //resetowanie flag b³êdu
				cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			} //lub do napotkania znaku nowej linii
			else break;
		}
		if (x >= _od && x <= _do)
			return x;
		else
			cout << "Prosze podac liczbe z zakresu od " << _od << " do " << _do << endl; //komunikat o b³êdzie
	}
}

int Interfejs::MenuWyboru(int& numerek)

{
	cout << numerek << ". Dodaj element" << endl; numerek++;
	cout << numerek << ". Usun wybrany element" << endl; numerek++;
	cout << numerek << ". Edytuj wybrany element" << endl; numerek++;
	cout << numerek << ". Wczytaj dane z pliku .CSV" << endl; numerek++;
	cout << numerek << ". Wyswietl caly zbior na terminalu" << endl; numerek++;
	cout << numerek << ". Zapisz jako plik .CSV" << endl; numerek++;
	cout << numerek << ". Zapisz jako plik .txt" << endl; numerek++;
	cout << numerek << ". Powrot" << endl;
	
	return bezpiecznyInt(1,numerek);
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
	Gospodarstwo.dodajPole(utworzPoleObiekt());
}

void Interfejs::dodawanieZabiegow()
{
	if (Gospodarstwo.getSizeParkMaszynowy() == 0 || Gospodarstwo.getSizeZiemiaUprawna() == 0) {
		cout << "Nie dodales pol i maszyn.\n"
			<< "Nie mozesz uzywac tego menu bez tych informacji.\n"
			<< "Uzyj opcji menu nr 2 i 3, aby dodac potrzebne dane." << endl;
		system("pause");
		return;
	}

	Zabieg noweZadanie;
	try
	{
		noweZadanie.setData(utworzDataObiekt());
	}
	catch (const out_of_range& exc)
	{
		system("cls");
		cerr << exc.what() << endl;
		system("pause");
	}
	
	system("cls");
	cout<<"Data wykonania zabiegu:\n" << noweZadanie.getData()<<endl;
	try
	{
		Gospodarstwo.wyswietlListePol();
	}
	catch (const domain_error& exc)
	{
		system("cls");
		cerr << exc.what() << endl;
		cout << "Uzyj opcji menu nr 2 i 3, aby uzupelnic potrzebne dane" << endl;
		system("pause");
		return;
	}
	cout << "\n";
	noweZadanie.setPole(wybierzPole());

	system("cls");
	cout << "Data wykonania zabiegu:\n" << noweZadanie.getData() << endl;
	cout << "Pole na ktory bedzie wykonany zabieg:\n" << noweZadanie.getPole()->getNazwa() << endl;
	try
	{
	Gospodarstwo.wyswietlListeMaszyn();
	}
	catch (const domain_error& exc)
	{
		system("cls");
		cerr << exc.what() << endl;
		cout << "Uzyj opcji menu nr 2 i 3, aby uzupelnic potrzebne dane" << endl;
		system("pause");
		return;
	}
	cout << "\n";
	int nrOpcji;
	noweZadanie.setMaszyna(wybierzMaszyne(nrOpcji));
	noweZadanie.wykonajZabieg(nrOpcji);
	system("cls");
	noweZadanie.wyswietl();
	system("pause");
	KalendarzZabiegow.dodajZabieg(noweZadanie);
}

Maszyna* Interfejs::wybierzMaszyne(int& numer)
{
	Maszyna* wskaznik;
	int indeksKolejki = bezpiecznyInt(1,(int) Gospodarstwo.getSizeParkMaszynowy()) - 1;

	if (Gospodarstwo.getMaszyna(indeksKolejki).getNazwa() == "Kultywator") numer = 2;
	else if (Gospodarstwo.getMaszyna(indeksKolejki).getNazwa() == "Rozsiewacz") numer = 1;
	else if (Gospodarstwo.getMaszyna(indeksKolejki).getNazwa() == "Siewnik") numer = 3;
	else if (Gospodarstwo.getMaszyna(indeksKolejki).getNazwa() == "Kombajn") numer = 4;
	
	wskaznik = &Gospodarstwo.getMaszyna(indeksKolejki);
	return wskaznik;
}

Pole* Interfejs::wybierzPole()
{
	Pole* wskaznik;
	int indeksKolejki = bezpiecznyInt(1,(int) Gospodarstwo.getSizeZiemiaUprawna()) - 1;
	wskaznik = &Gospodarstwo.getPole(indeksKolejki);
	return wskaznik;
}

void Interfejs::dodawanieMaszyn()
{
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

		switch (bezpiecznyInt(1, numerek))
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
	string nowaNazwa;
	float nowaPowierzchnia;
	cout << "Wybierz element ktory chcesz edytowac:" << endl;
	cout << "1.Nazwa:" << _pole.getNazwa() << endl;
	cout << "2.Powierzchnia pola[ha]:" << _pole.getPowierzchnia();
	cout << "3.Opcja resetowania powierzchnia pola" << endl;
	cout << "4.Powrot" << endl;
	switch (bezpiecznyInt(1,4))
	{
	case 1:
		getline(cin,nowaNazwa);
		_pole.setNazwa(nowaNazwa);
		break;
	case 2:
		nowaPowierzchnia = bezpiecznyFloat(0);
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

void Interfejs::edycjaZabiegow(std::list<Zabieg>::iterator _obiekt)
{
	int indeks;
	cout << "Wybierz element ktory chcesz edytowac:" << endl;
	cout << "1.Data:" << _obiekt->getData() << endl;
	cout << "2.Maszyna:" << _obiekt->getMaszyna()->getNazwa() << endl;
	cout << "3.Pole: "<< _obiekt->getPole()->getNazwa() << endl;
	cout << "4.Powrot" << endl;
	switch (bezpiecznyInt(1, 4))
	{
	case 1:
		_obiekt->setData(utworzDataObiekt());
		break;
	case 2:
		try{
		Gospodarstwo.wyswietlListeMaszyn();
		}
		catch (domain_error& exc) {
			cerr << exc.what() << endl;
			system("pause");
			return;
		}
		_obiekt->setMaszyna(wybierzMaszyne(indeks));
		break;
	case 3:
		try {
			Gospodarstwo.wyswietlListePol();
		}
		catch (domain_error& exc) {
			cerr << exc.what() << endl;
			system("pause");
			return;
		}
		_obiekt->setPole(wybierzPole());
		break;
	case 4:
	default:
		break;
	}
}

string Interfejs::podajSciezke(const char* _rozszerzenie)
{
	string sciezka;
	cout << "Podaj nazwe pliku.\n" << "Nie podawaj rozszerzenia zostanie dopisane automatycznie" << endl;
	cin >> sciezka;

	size_t pozycja = sciezka.find(_rozszerzenie);
	if (pozycja == string::npos)
	sciezka += _rozszerzenie;
	
	return sciezka;
}

Data Interfejs::utworzDataObiekt()
{
	
	int dzien, miesiac, rok;

	system("cls");
	cout << "Podaj rok wykonania zabiegu:" << endl;
	rok = bezpiecznyInt(1901, 2199);

	system("cls");
	cout << "Podaj miesiac wykonania zabiegu:" << endl;
	miesiac = bezpiecznyInt(1, 12);

	system("cls");
	cout << "Podaj dzien wykonania zabiegu:" << endl;
	dzien = bezpiecznyInt(1, Data::monthLength(miesiac, Data::isLeap(rok)));
	
	return Data(dzien,miesiac,rok);
}

Pole Interfejs::utworzPoleObiekt()
{
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

	return Pole(_nazwa,_powierzchnia);
}
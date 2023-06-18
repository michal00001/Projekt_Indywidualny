#pragma once

#include "Kalendarz.h"
#include "Gospodarstwo.h"

using namespace std;

inline string DatatoString(Data& _data) {
	string out = to_string(_data.getDzien()) + ";" + to_string(_data.getMiesiac()) + ";" + to_string(_data.getRok());
	return out;
}
//Specyfikator inline informuje kompilator, ¿e funkcje mo¿na zdefiniowaæ wielokrotnie w ró¿nych miejscach, ale nale¿y je traktowaæ jako jedno. 
inline string PoletoString(Pole& _pole, int _opcja) {
	string out;
	if (_opcja == 0)
		out = _pole.getNazwa() + ";" + to_string(_pole.getPowierzchnia()) + ";" + to_string(_pole.getstadiumWzrostu());
	else if (_opcja == 1)
		out = _pole.getNazwa() + " " + to_string(_pole.getPowierzchnia()) + " " + to_string(_pole.getstadiumWzrostu());

	return out;
}

class Drukarka {
private:
	bool operator==(const Drukarka& other) const {};

public:
	virtual void drukuj(list<Zabieg>& _listaZabiegow, int _ile,const char* sciezka = "\0") const = 0;

	virtual void drukuj(deque<Maszyna>& _ParkMaszynowy, int _ile, const char* sciezka = "\0") const = 0;
	
	virtual void drukuj(deque<Pole>& _ZiemiaUprawna, int _ile, const char* sciezka = "\0") const = 0;
};


class TerminalDrukarka : public Drukarka
{
public:
	void drukuj(list<Zabieg>& _listaZabiegow, int _ile, const char* sciezka = "\0") const override {

		//nawet jezeli ile bedzie poza rozmiarem to wydrukuje sie tylko tyle ile jest w tablicy

		if (_listaZabiegow.empty())
			throw domain_error("Kalendarz zabiegow jest pusty");
		string numerPorzadkowy;
		string drukuj;
		string naglowek[] = {"Data" ,"Maszyna","Pole" };
		int ileWydrukowano = 0;

		//naglowek tabelki
		cout.fill('-');
		cout << "|" << setw(15) << "|";
		cout.fill(' ');
		cout << setw(15) << naglowek[0];
		cout << "|" << setw(15) << naglowek[1];
		cout << "|" << setw(20) << naglowek[2];
			cout << "|" << endl;
		for (auto _Iter=_listaZabiegow.begin();_Iter!=_listaZabiegow.end();_Iter++)
		{
			if (ileWydrukowano < _ile)
			{
				numerPorzadkowy = to_string(ileWydrukowano + 1) + ".";
				drukuj = "Zabieg nr " + numerPorzadkowy;

				cout << "|" << setw(14) << drukuj;
				cout << "|" << setw(15) << _Iter->getData();
				cout.fill(' ');
				cout << "|" << setw(15) << (*_Iter).getMaszyna()->getNazwa();
				cout << "|" << setw(20) << _Iter->getPole()->getNazwa();
				cout << "|" << endl;
				ileWydrukowano++;
			}
		}
		
	};

	void drukuj(deque<Maszyna>& _ParkMaszynowy, int _ile, const char* sciezka = "\0") const override {

		//nawet jezeli ile bedzie poza rozmiarem to wydrukuje sie tylko tyle ile jest w tablicy

		if (_ParkMaszynowy.empty()) {
			throw domain_error("Lista maszyn jest pusta");
		}
		string numerPorzadkowy;
		string naglowek[] = {"LP", "Nazwa" ,"Typ Maszyny" };
		string typMaszyny[] = { "Do Nawozenia" ,"Do Uprawy", "Do Siewu", "Do Zbioru" ,"Ugor" };
		int ileWydrukowano = 0;

		cout.fill(' ');
		cout << "|" << setw(4) << naglowek[0];
		cout << "|" << setw(15) << naglowek[1];
		cout << "|" << setw(15) << naglowek[2];
		cout << "|" << endl;

		for (auto maszyna : _ParkMaszynowy)
		{
			if (ileWydrukowano < _ile)
			{
				numerPorzadkowy = to_string(ileWydrukowano + 1)+".";
				cout.fill(' ');
				cout << "|" << setw(4) << numerPorzadkowy;
				cout << "|" << setw(15) << maszyna.getNazwa();
				cout << "|" << setw(15);
				if (maszyna.getdoNawozenia())		cout << typMaszyny[0];
				else if (maszyna.getdoUprawy())		cout << typMaszyny[1];
				else if (maszyna.getdoSiewu())		cout << typMaszyny[2];
				else if (maszyna.getdoZbioru())		cout << typMaszyny[3];
				else cout << typMaszyny[4];
				cout << "|" << endl;
				ileWydrukowano++;
			}
		}
	}
	
	void drukuj(deque<Pole>& _ZiemiaUprawna, int _ile, const char* _sciezka = "\0") const override {

		//nawet jezeli ile bedzie poza rozmiarem to wydrukuje sie tylko tyle ile jest w tablicy
		if (_ZiemiaUprawna.empty()) {
			throw domain_error("Lista pol jest pusta");
		}

		string numerPorzadkowy;
		string naglowek[] = { "LP","Nazwa" ,"Powierzchnia","Stadium Wzrostu", "Stan pola" };
		string stanPol[] = { "Nawieziono" ,"Uprawiono", "Zasiano", "Zebrano" ,"Ugor" };
		int ileWydrukowano = 0;

		cout.fill(' ');
		cout << "|" << setw(4) << naglowek[0];
		cout << "|" << setw(15) << naglowek[1];
		cout << "|" << setw(15) << naglowek[2];
		cout << "|" << setw(15) << naglowek[3];
		cout << "|" << setw(12) << naglowek[4];
		cout << "|" << endl;

		for (auto pole : _ZiemiaUprawna)
		{
			if (ileWydrukowano < _ile)
			{
				numerPorzadkowy = to_string(ileWydrukowano + 1) + ".";
				cout.fill(' ');
				cout << "|" << setw(4) << numerPorzadkowy;
				cout  << "|" << setw(15) << pole.getNazwa();
				cout  << "|" << setw(15) << pole.getPowierzchnia();
				cout  << "|" << setw(15) << pole.getstadiumWzrostu();
				cout  << "|" << setw(12);
				if (pole.czyNawieziono())		cout << stanPol[0];
				else if (pole.czyUprawiono())	cout << stanPol[1];
				else if (pole.czyZasiano())		cout << stanPol[2];
				else if (pole.czyZebrano())		cout << stanPol[3];
				else							cout << stanPol[4];
				cout << "|" << endl;
				ileWydrukowano++;
			}
			else
				break;
		}
	}
};


class CSVDrukarka : public Drukarka
{
public:

	void drukuj(list<Zabieg>& _listaZabiegow,int _ile,const char* _sciezka="ZabiegPlik.csv") const override {
		if (_listaZabiegow.empty())
			throw domain_error("Kalendarz zabiegow jest pusty");

			fstream plik;
			string naglowek[] = { "Data", "Maszyna","Pole" };
			string naglowek2[] = { "Dzien","Miesiac","Rok","Nazwa","Powierzchnia [ha]","Status wzrostu" };
			string deli = ";";
			list<Zabieg>::iterator _Iter;

			plik.open(_sciezka, ofstream::out);
			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych\n";
			plik.fill(' ');
			//naglowek 
			//data;data;data
			plik << naglowek[0] << deli << naglowek[0] << deli << naglowek[0] << deli;
			//maszyna
			plik << naglowek[1] << deli;
			//pole;pole;pole
			plik << naglowek[2] << deli << naglowek[2] << deli << naglowek[2]  << endl;
			//naglowek 2
			// dzien ; miesiac ; rok
			plik << naglowek2[0] << deli << naglowek2[1] << deli << naglowek2[2]<<deli;
			// nazwa
			plik << naglowek2[3] << deli;
			// nazwa ; powierzchnia[ha] ; status wzrostu
			plik << naglowek2[3] << deli << naglowek2[4] << deli << naglowek2[5] << endl;
			for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
			{
				// dzien ; miesiac ; rok
				plik << _Iter->getData().getDzien() << deli << _Iter->getData().getMiesiac() << deli << _Iter->getData().getRok() << deli;
				// nazwa
				plik << _Iter->getMaszyna()->getNazwa() << deli;
				// nazwa ; powierzchnia[ha] ; status wzrostu
				plik << _Iter->getPole()->getNazwa() << deli << _Iter->getPole()->getPowierzchnia() << deli << _Iter->getPole()->getstadiumWzrostu() << std::endl;
			}
			plik.close();

	}

	void drukuj(deque<Maszyna>& _ParkMaszynowy, int _ile, const char* _sciezka) const override{
		if (_ParkMaszynowy.empty())
			throw domain_error("Kalendarz zabiegow jest pusty");

			std::ofstream plik;
			plik.open(_sciezka, ofstream::out);

			if (!plik.is_open()) {
				std::cout << "B³¹d: Nie mo¿na otworzyæ pliku." << std::endl;
				return;
			}

			plik << "Nazwa;doUprawy;doSiewu;doNawozenia;doZbioru" << std::endl;
			// Tworzenie kopii kolejki
			std::deque<Maszyna> kopiaKolejki = _ParkMaszynowy; 

			while (!kopiaKolejki.empty()) {
				const std::deque<Maszyna>::iterator::value_type maszyna = kopiaKolejki.front();

				plik << maszyna.getNazwa() << ";"
					<< (maszyna.getdoUprawy() ? "Tak" : "Nie") << ";"
					<< (maszyna.getdoSiewu() ? "Tak" : "Nie") << ";"
					<< (maszyna.getdoNawozenia() ? "Tak" : "Nie") << ";"
					<< (maszyna.getdoZbioru() ? "Tak" : "Nie") << std::endl;

				//usuniecie pierwszego elementu kolejki
				kopiaKolejki.pop_front();
			}

			plik.close();
			std::cout << "Plik zapisany pomyœlnie." << std::endl;
	}

	void drukuj(deque<Pole>& _ZiemiaUprawna, int _ile, const char* _sciezka = "PolePlik.csv") const override {
		{
			std::ofstream plik;
			plik.open(_sciezka, ofstream::out);
			if (!plik.is_open()) {
				std::cout << "B³¹d: Nie mo¿na otworzyæ pliku." << std::endl;
				return;
			}
			plik << "Nazwa" << ";" << "Powierzchnia[ha]" << ";" << "Stadium Wzrostu" << ";" << "Uprawion" << ";" << "Nawieziono" << ";" << "Zasiano" << ";" << "Zebrano" << endl;
			for (Pole& pole : _ZiemiaUprawna)
			{
				plik << pole.getNazwa() << ";";
				plik << setw(5) << pole.getPowierzchnia() << ";";
				plik << setw(1) << pole.getstadiumWzrostu() << ";";
				plik << (pole.czyUprawiono() ? "Tak" : "Nie") << ";";
				plik << (pole.czyNawieziono() ? "Tak" : "Nie") << ";";
				plik << (pole.czyZasiano() ? "Tak" : "Nie") << ";";
				plik << (pole.czyZebrano() ? "Tak" : "Nie") << "\n";
			}
			plik.close();
			std::cout << "Plik zapisany pomyœlnie." << std::endl;
		}
	}
};


template <typename T>
class DrukarkaFactory {
public:
	static unique_ptr<Drukarka> stworzDrukarke() {
		return make_unique<T>();
	}
};



/*
class TxtDrukarka : public Drukarka
{
public:
	void drukuj(list<Zabieg>& _listaZabiegow) const override {
		char sciezka[] = "Przyklad.txt";
		drukuj(_listaZabiegow, sciezka);
	};
	void drukuj(list<Zabieg>& _listaZabiegow, int _ile) const override {
		if (_listaZabiegow.empty())
			throw domain_error("Kalendarz zabiegow jest pusty");
		else {
			char sciezka[] = "PrzykladKalendarz.txt";
			fstream plik;
			list<Zabieg>::iterator _Iter;
			list<Zabieg>::iterator _Iter2 = _listaZabiegow.end();

			for (int i = 0; i < _ile; i++)
			{
				if (_Iter2 != _listaZabiegow.end())
				{
					_Iter2++;
				}
			}

			plik.open(sciezka, ofstream::out);

			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych do pliku " << sciezka << "\n";
			plik.fill(' ');
			plik << "|" << setw(8) << "Data" << setw(5) << "|" << setw(14) << "Maszyna" << setw(7) << "|" << setw(15) << "Pole" << setw(12) << "|" << endl;
			for (_Iter = _listaZabiegow.begin(); _Iter != _Iter2; _Iter++)
			{
				//plik << "| " << (*_Iter).getData() << " |" << setfill(' ') << setw(15) << (*_Iter).getMaszyna() << setw(6) << "|" << setw(26) << PoletoString((*_Iter).getPole(), 1) << "|" << endl;
			}
			plik.close();
		}
	};
	void drukuj(list<Zabieg>& _listaZabiegow, char* _sciezka) const override {
		if (_listaZabiegow.empty())
			throw domain_error("Kalendarz zabiegow jest pusty");
		else {
			fstream plik;
			list<Zabieg>::iterator _Iter;

			plik.open(_sciezka, ofstream::out);

			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych do pliku " << _sciezka << "\n";
			plik.fill(' ');
			plik << "|" << setw(8) << "Data" << setw(5) << "|" << setw(14) << "Maszyna" << setw(7) << "|" << setw(15) << "Pole" << setw(12) << "|" << endl;
			for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
			{
				//plik << "| " << (*_Iter).getData() << " |" << setfill(' ') << setw(15) << (*_Iter).getMaszyna() << setw(6) << "|" << setw(26) << PoletoString((*_Iter).getPole(), 1) << "|" << endl;
			}
			plik.close();
		}
	};
	void drukuj(deque<Maszyna>& _ParkMaszynowy) const override {
		char sciezka[] = "Przyklad_maszyn.txt";
		drukuj(_ParkMaszynowy, sciezka);

	};
	void drukuj(deque<Maszyna>& _ParkMaszynowy, int _ile) const override {
		char sciezka[] = "Przyklad_maszyn.txt";
		int liczba_wydrukowanych = 0;

		if (_ParkMaszynowy.empty())
			throw domain_error("Kalendarz zabiegow jest pusty");
		else {
			fstream plik;
			list<Zabieg>::iterator _Iter;

			plik.open(sciezka, ofstream::out);

			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych do pliku " << sciezka << "\n";
			plik.fill(' ');
			plik << "|" << setw(8) << "Nazwa" << setw(5) << "|" << setw(14) << "Maszyna do uprawy" << setw(7) << "|" << setw(15) << "Maszyna do siewu" << setw(12) << "|"
				<< setw(15) << "Maszyna do nawozenia" << setw(12) << "|" << setw(15) << "Maszyna do zbioru" << setw(12) << "|" << endl;

			for (const Maszyna& maszyna : _ParkMaszynowy) {
				if (liczba_wydrukowanych < _ile && liczba_wydrukowanych != _ParkMaszynowy.size()) {
					plik << "|" << setfill(' ') << setw(13) << maszyna.getNazwa() << "|" << setfill(' ') << setw(15) << maszyna.getdoUprawy() << setw(6) << "|"
						<< setw(26) << maszyna.getdoSiewu() << "|" << setw(26) << maszyna.getdoNawozenia() << "|" << setw(26) << maszyna.getdoZbioru() << "|" << endl;
					liczba_wydrukowanych++;
				}
				else {
					break;
				}
			}

			plik.close();
		}
	};
	void drukuj(deque<Maszyna>& _ParkMaszynowy, char* _sciezka) const override {
		if (_ParkMaszynowy.empty())
			throw domain_error("Kalendarz zabiegow jest pusty");
		else {
			fstream plik;
			list<Zabieg>::iterator _Iter;

			plik.open(_sciezka, ofstream::out);

			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych do pliku " << _sciezka << "\n";
			plik.fill(' ');
			plik << "|" << setw(8) << "Nazwa" << setw(5) << "|" << setw(14) << "Maszyna do uprawy" << setw(7) << "|" << setw(15) << "Maszyna do siewu" << setw(12) << "|"
				<< setw(15) << "Maszyna do nawozenia" << setw(12) << "|" << setw(15) << "Maszyna do zbioru" << setw(12) << "|" << endl;

			for (const Maszyna& maszyna : _ParkMaszynowy) {
				plik << "|" << setfill(' ') << setw(13) << maszyna.getNazwa() << "|" << setfill(' ') << setw(15) << maszyna.getdoUprawy() << setw(6) << "|"
					<< setw(26) << maszyna.getdoSiewu() << "|" << setw(26) << maszyna.getdoNawozenia() << "|" << setw(26) << maszyna.getdoZbioru() << "|" << endl;
			}

			plik.close();
		}
	};
	void drukuj(deque<Pole>& _ZiemiaUprawna) const override {
		char sciezka[] = "PrzykladPole.txt";
		drukuj(_ZiemiaUprawna, sciezka);
	};
	void drukuj(deque<Pole>& _ZiemiaUprawna, int _ile) const override {

		if (_ZiemiaUprawna.empty())
			throw domain_error("Kalendarz zabiegow jest pusty");
		else {
			char sciezka[] = "PrzykladPole.txt";
			fstream plik;
			int liczbawydrukowanych = 0;
			plik.open(sciezka, ofstream::out);

			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych do pliku " << sciezka << "\n";
			plik.fill(' ');
			plik << "Nazwa";			plik << "Powierzchnia";			plik << "Stadium wzrostu";			plik << "Nawieziono";			plik << "Uprawiono";			plik << "Zasiano";			plik << "Zebrano" << endl;
			for (Pole& poletko : _ZiemiaUprawna) {
				if (liczbawydrukowanych < _ile && _ile != _ZiemiaUprawna.size())
				{
					plik << poletko.getNazwa();
					plik << poletko.getPowierzchnia();
					plik << poletko.getstadiumWzrostu();
					plik << poletko.czyNawieziono();
					plik << poletko.czyUprawiono();
					plik << poletko.czyZasiano();
					plik << poletko.czyZebrano();

				}
				else
					break;
			}
			plik.close();
		}
	};
	void drukuj(deque<Pole>& _ZiemiaUprawna, char* _sciezka) const override {
		if (_ZiemiaUprawna.empty())
			throw domain_error("Kalendarz zabiegow jest pusty");
		else {
			fstream plik;

			plik.open(_sciezka, ofstream::out);

			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych do pliku " << _sciezka << "\n";
			plik.fill(' ');
			plik << "Nazwa";
			plik << "Powierzchnia";
			plik << "Stadium wzrostu";
			plik << "Nawieziono";
			plik << "Uprawiono";
			plik << "Zasiano";
			plik << "Zebrano" << endl;
			for (Pole& poletko : _ZiemiaUprawna) {
				plik << poletko.getNazwa();
				plik << poletko.getPowierzchnia();
				plik << poletko.getstadiumWzrostu();
				plik << poletko.czyNawieziono();
				plik << poletko.czyUprawiono();
				plik << poletko.czyZasiano();
				plik << poletko.czyZebrano();
			}

			plik.close();
		}
	};
};
*/

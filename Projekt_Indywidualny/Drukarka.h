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
		else {
			using namespace std;
	
			int ileWydrukowano = 0;
			//naglowek tabelki
			cout.fill(' ');
			cout << "|" << setw(8) << "Data" << setw(6) << "|" << setw(14) << "Maszyna" << setw(10)
				<< "|" << setw(25) << "Pole" << setw(22) << "|" << endl;
			for (const Zabieg& _Iter:_listaZabiegow)
			{
				if (ileWydrukowano < _ile)
				{
					//cout << DatatoString((*_Iter).getData()) << ";" << (*_Iter).getMaszyna() << ";" << PoletoString((*_Iter).getPole(), 1) << endl;
					ileWydrukowano++;
				}
			}
		}
	};

	void drukuj(deque<Maszyna>& _ParkMaszynowy, int _ile, const char* sciezka = "\0") const override {

		//nawet jezeli ile bedzie poza rozmiarem to wydrukuje sie tylko tyle ile jest w tablicy

		if (_ParkMaszynowy.empty()) {
			throw domain_error("Lista maszyn jest pusta");
		}

		int ileWydrukowano = 0;
		cout << "|" << "Nazwa" << "|" << "Typ Maszyny" << "|" << endl;

		for (Maszyna& maszyna : _ParkMaszynowy)
		{
			if (ileWydrukowano < _ile)
			{
				cout << maszyna.getNazwa() << endl;
				ileWydrukowano++;
			}
		}
	}
	
	void drukuj(deque<Pole>& _ZiemiaUprawna, int _ile, const char* _sciezka = "\0") const override {

		//nawet jezeli ile bedzie poza rozmiarem to wydrukuje sie tylko tyle ile jest w tablicy

		if (_ZiemiaUprawna.empty()) {
			throw domain_error("Lista pol jest pusta");
		}

		int ileWydrukowano = 0;
		cout << "|" << "Nazwa" << "|" << "Powierzchnia" << "|" << "Stadium Wzrostu" << "|" << "Stan pola" << "|" << endl;

		for (Pole& pole : _ZiemiaUprawna)
		{
			if (ileWydrukowano < _ile)
			{
				cout << "|" << pole.getNazwa() << "|" << to_string(pole.getPowierzchnia()) << "|" << pole.getstadiumWzrostu() << "|";
				if (pole.czyNawieziono()) cout << "Nawieziono";
				else if (pole.czyUprawiono()) cout << "Uprawiono";
				else if (pole.czyZasiano()) cout << "Zasiano";
				else if (pole.czyZebrano()) cout << "Zebrano";
				else cout << "Ugor";
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
			list<Zabieg>::iterator _Iter;

			plik.open(_sciezka, ofstream::out);
			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych\n";
			plik.fill(' ');
			plik << "Data" << ";" << "Data" << ";" << "Data" << ";" << "Maszyna" << ";" << "Pole" << ";" << "Pole" << ";" << "Pole" << endl;
			plik << "Dzien" << ";" << "Miesiac" << ";" << "Rok" << ";" << "Nazwa" << ";" << "Nazwa" << ";" << "Powierzchnia [ha]" << ";" << "Status wzrostu" << endl;
			for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
			{
			//	plik << DatatoString((*_Iter).getData()) << ";" << (*_Iter).getMaszyna() << ";" << PoletoString((*_Iter).getPole(), 0) << endl;
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
			std::deque<Maszyna> kopiaKolejki = _ParkMaszynowy; // Tworzenie kopii kolejki

			while (!kopiaKolejki.empty()) {
				const Maszyna& maszyna = kopiaKolejki.front();

				plik << maszyna.getNazwa() << ";"
					<< (maszyna.getdoUprawy() ? "Tak" : "Nie") << ";"
					<< (maszyna.getdoSiewu() ? "Tak" : "Nie") << ";"
					<< (maszyna.getdoNawozenia() ? "Tak" : "Nie") << ";"
					<< (maszyna.getdoZbioru() ? "Tak" : "Nie") << std::endl;

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
				plik << pole.getNazwa() << ";"
					<< pole.getPowierzchnia() << ";"
					<< pole.getstadiumWzrostu() << ";"
					<< (pole.czyUprawiono() ? "Tak" : "Nie") << ";"
					<< (pole.czyNawieziono() ? "Tak" : "Nie") << ";"
					<< (pole.czyZasiano() ? "Tak" : "Nie") << ";"
					<< (pole.czyZebrano() ? "Tak" : "Nie") << "\n";
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

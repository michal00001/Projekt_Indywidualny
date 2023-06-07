#pragma once
#include "Kalendarz.h"

std::string DatatoString(Data& _data){
	std::string out = std::to_string(_data.getDzien()) + ";" + std::to_string(_data.getMiesiac()) + ";" + std::to_string(_data.getRok());
	return out;
}

std::string PoletoString(Pole& _pole, int _opcja){
	std::string out;
	if(_opcja == 0)
	 out = _pole.getNazwa() + ";" + std::to_string(_pole.getPowierzchnia()) + ";" + std::to_string(_pole.getstadiumWzrostu());
	else if(_opcja == 1)
	 out = _pole.getNazwa() + " " + std::to_string(_pole.getPowierzchnia()) + " " + std::to_string(_pole.getstadiumWzrostu());

	return out;
}

class Drukarka {
public:
	virtual void drukuj(std::list<Zabieg>& _listaZabiegow) const = 0;
};

class TxtDrukarka : public Drukarka
{
public:
	void drukuj(std::list<Zabieg>& _listaZabiegow) const override {
		char sciezka[] = "Przyklad.txt";
		drukuj(_listaZabiegow, sciezka);
	};

	void drukuj(std::list<Zabieg>& _listaZabiegow,char* _sciezka) const {
		if (_listaZabiegow.size() == 0)
			throw std::domain_error("Kalendarz zabiegow jest pusty");
		else {
			std::fstream plik;
			std::list<Zabieg>::iterator _Iter;

			plik.open(_sciezka, std::ofstream::out);

			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych do pliku " << _sciezka << "\n";
			plik.fill(' ');
			plik << "|" << std::setw(8) << "Data" << std::setw(5) << "|" << std::setw(14) << "Maszyna" << std::setw(7) << "|" << std::setw(15) << "Pole" << std::setw(12) << "|" << std::endl;
			for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
			{
				plik << "| " << (*_Iter).getData() << " |" << std::setfill(' ') << std::setw(15) << (*_Iter).getMaszyna() << std::setw(6) << "|" << std::setw(26) << PoletoString((*_Iter).getPole(), 1) << "|" << std::endl;
			}
			plik.close();
		}
	};
};

class CsvDrukarka : public Drukarka
{
public:
	void drukuj(std::list<Zabieg>& _listaZabiegow) const override {
		char sciezka[] = "Przyklad.csv";
		drukuj(_listaZabiegow, sciezka);
	};

	void drukuj(std::list<Zabieg>& _listaZabiegow,char * _sciezka)const {
		if (_listaZabiegow.size() == 0)
			throw std::domain_error("Kalendarz zabiegow jest pusty");
		else {
			std::fstream plik;
			std::list<Zabieg>::iterator _Iter;

			plik.open(_sciezka, std::ofstream::out);
			if (!plik.is_open())
				return;//blad

			plik << "Zapis danych\n";
			plik.fill(' ');
			plik << "Data" << ";" << "Data" << ";" << "Data" << ";" << "Maszyna" << ";" << "Pole" << ";" << "Pole" << ";" << "Pole" << std::endl;
			plik << "Dzien" << ";" << "Miesiac" << ";" << "Rok" << ";" << "Nazwa" << ";" << "Nazwa" << ";" << "Powierzchnia [ha]" << ";" << "Status wzrostu" << std::endl;
			for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
			{
				plik << DatatoString((*_Iter).getData()) << ";" << (*_Iter).getMaszyna() << ";" << PoletoString((*_Iter).getPole(), 0) << std::endl;
			}
			plik.close();
		}
	};
};

class TerminalDrukarka : public Drukarka
{
public:
	void drukuj(std::list<Zabieg>& _listaZabiegow) const override {
		if (_listaZabiegow.size() == 0)
			throw std::domain_error("Kalendarz zabiegow jest pusty");
		else {
			using namespace std;
			list<Zabieg>::iterator _Iter;

			//naglowek tabelki
			cout.fill(' ');
			cout << "|" << std::setw(8) << "Data" << std::setw(6) << "|" << std::setw(14) << "Maszyna" << std::setw(10)
				<< "|" << std::setw(25) << "Pole" << std::setw(22) << "|" << std::endl;
			for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
			{
				std::cout << DatatoString((*_Iter).getData()) << ";" << (*_Iter).getMaszyna() << ";" << PoletoString((*_Iter).getPole(), 1) << std::endl;
			}
		}
	}
};


template <typename T>
class DrukarkaFactory {
public:
	static std::unique_ptr<Drukarka> stworzDrukarke() {
		return std::make_unique<T>();
	}
};
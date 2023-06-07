#pragma once
#include "Kalendarz.h"

class Drukarka {
public:
	virtual void drukuj(std::list<Zabieg>& _listaZabiegow) const = 0;
	virtual void drukuj(std::list<Zabieg>& _listaZabiegow, char* _sciezka) const = 0;
};

std::string DatatoString(Data& _data){
	std::string out = std::to_string(_data.getDzien()) + ";" + std::to_string(_data.getMiesiac()) + ";" + std::to_string(_data.getRok());
	return out;
}
std::string PoletoString(Pole& _pole){
	std::string out = _pole.getNazwa() + ";" + std::to_string(_pole.getPowierzchnia()) + ";" + std::to_string(_pole.getstadiumWzrostu());
	return out;
}

class TxtDrukarka : public Drukarka
{
public:
	void drukuj(std::list<Zabieg>& _listaZabiegow, char* _sciezka) const override {
		std::fstream plik;
		std::list<Zabieg>::iterator _Iter;

		plik.open(_sciezka, std::ofstream::out);

		if (!plik.is_open())
			return;//blad

		plik << "Zapis danych do pliku "<<_sciezka<<"\n";
		plik.fill(' ');
		plik << "|" << std::setw(8) << "Data" << std::setw(6) << "|" << std::setw(14) << "Maszyna" << std::setw(10)
			<< "|" << std::setw(25) << "Pole" << std::setw(22) << "|" << std::endl;
		for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
		{
			plik << "|" << (*_Iter).getData() << "|"<<(*_Iter).getMaszyna()<<"|"<<(*_Iter).getPole()<<"|" << std::endl;
		}
		plik.close();
	};
	
};

class CsvDrukarka : public Drukarka
{
public:
	void drukuj(std::list<Zabieg>& _listaZabiegow, char* _sciezka) const override {
		std::fstream plik;
		std::list<Zabieg>::iterator _Iter;

		plik.open(_sciezka, std::ofstream::out);
		if (!plik.is_open())
			return;//blad

		plik << "Zapis danych\n";
		plik.fill(' ');
		plik << "Data" << ";" << "Maszyna" << ";" << "Pole" << std::endl;
		plik << "Dzien" << ";" << "Miesiac" << ";" << "Rok" << ";" << "Nazwa" << ";" << "Powierzchnia [ha]" << ";" << "Nazwa" << ";" << "Status wzrostu" << std::endl;
		for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
		{
			plik << DatatoString((*_Iter).getData()) << ";" << (*_Iter).getMaszyna() << ";" << PoletoString((*_Iter).getPole()) << std::endl;
		}
		plik.close();
	};

};

class TerminalDrukarka : public Drukarka
{
public :
	void drukuj(std::list<Zabieg>& _listaZabiegow) const override {
		//naglowek tabelki
		using namespace std;
		list<Zabieg>::iterator _Iter;

		cout.fill(' ');
		cout << "|" << std::setw(8) << "Data" << std::setw(6) << "|" << std::setw(14) << "Maszyna" << std::setw(10)
			<< "|" << std::setw(25) << "Pole" << std::setw(22) << "|" << std::endl;
		for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
		{
			std::cout << DatatoString((*_Iter).getData()) << ";" << (*_Iter).getMaszyna() << ";" << PoletoString((*_Iter).getPole()) << std::endl;
		}
	};

	void drukuj(std::list<Zabieg>& _listaZabiegow,char* _sciezka) const override {
		//naglowek tabelki
		using namespace std;
		list<Zabieg>::iterator _Iter;

		cout.fill(' ');
		cout << "|" << std::setw(8) << "Data" << std::setw(6) << "|" << std::setw(14) << "Maszyna" << std::setw(10)
			<< "|" << std::setw(25) << "Pole" << std::setw(22) << "|" << std::endl;
		for (_Iter = _listaZabiegow.begin(); _Iter != _listaZabiegow.end(); _Iter++)
		{
			std::cout << DatatoString((*_Iter).getData()) << ";" << (*_Iter).getMaszyna() << ";" << PoletoString((*_Iter).getPole()) << std::endl;
		}
	};
};

template <typename T>
class DrukarkaFactory {
public:
	static std::unique_ptr<Drukarka> stworzDrukarke() {
		return std::make_unique<T>();
	}
};
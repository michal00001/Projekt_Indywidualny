#pragma once

#include <queue>
#include <sstream>
#include <fstream>

#include "Drukarka.h"
#include "Maszyna.h"
#include "Pole.h"


class Gospodarstwo
{
private:
	std::deque<Pole> ZiemiaUprawna;
	std::deque<Maszyna> ParkMaszynowy;
public:
	void dodajMaszyne(Maszyna _obiekt);
	//void edytujMaszyne(std::deque<Maszyna>::iterator _maszyna);
	void usunMaszyne(int _pozycja);
	void zapiszMaszynyCSV(const char* _sciezka);

	void wyswietlListeMaszyn();
	void wyswietlListeMaszyn(int _ile);
	void wyswietlListePol();
	void wyswietlListePol(int _ile);


	void dodajPole(Pole _obiekt);
	void edytujPole(Pole& pole, std::string _nazwa, float _powierzchnia);
	void usunPole(int _pozycja);
	void zapiszPoleCSV(const char* _sciezka);

	Maszyna& getMaszyna(int _indeks);
	Pole& getPole(int _indeks);

	std::size_t getSizeZiemiaUprawna() const{ return ZiemiaUprawna.size(); };
	std::size_t getSizeParkMaszynowy() const{ return ParkMaszynowy.size(); };

	bool sprawdzCzyNieWystepuje(Maszyna& _obiekt)const;
	bool sprawdzCzyNieWystepuje(Pole& _obiekt)const;

	void wyczyscGospodarstwo();

	void odczytajMaszynyZPliku(const char* sciezka);
    void odczytajPolaZPliku(const char* sciezka);

};


#pragma once
#include <fstream>
#include <queue>
#include <sstream>
#include "Maszyna.h"
#include "Pole.h"
#include "Drukarka.h"


class Gospodarstwo
{
private:
	std::deque<Pole> ZiemiaUprawna;
	std::deque<Maszyna> ParkMaszynowy;
public:
	void dodajMaszyne();
	void dodajMaszyne(Maszyna _obiekt);

	void usunMaszyne(int _pozycja);

	void wyswietlListeMaszyn();
	void wyswietlListeMaszyn(int _ile);
	void wyswietlListePol();
	void wyswietlListePol(int _ile);

	void zapiszCSV();

	void dodajPole(Pole _obiekt);

	void usunPole(int _pozycja);

	Maszyna& getMaszyna(int _miejsce);
	Pole& getPole(int _miejsce);

	std::size_t getSizeZiemiaUprawna() const{ return ZiemiaUprawna.size(); };
	std::size_t getSizeParkMaszynowy() const{ return ParkMaszynowy.size(); };

	bool czyParkMaszynowyPusty() const;
	bool czyZiemiaUprawnaPusta() const;

	bool sprawdzCzyNieWystepuje(Maszyna& _obiekt)const;
	bool sprawdzCzyNieWystepuje(Pole& _obiekt)const;

	void wyczyscGospodarstwo();

	void odczytajMaszynyZPliku(char* sciezka);
    void odczytajPolaZPliku(const std::string& nazwaPliku);

};


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


	void dodajPole(Pole _obiekt);
	void edytujPole(std::deque<Pole>::iterator pole);
	void usunPole(int _pozycja);
	void zapiszPoleCSV(char* sciezka);

	std::deque<Maszyna>::iterator getMaszyna(int _miejsce);
	std::deque<Pole>::iterator getPole(int _miejsce);

	std::size_t getSizeZiemiaUprawna() const{ return ZiemiaUprawna.size(); };
	std::size_t getSizeParkMaszynowy() const{ return ParkMaszynowy.size(); };

	bool czyParkMaszynowyPusty() const;
	bool czyZiemiaUprawnaPusta() const;

	bool sprawdzCzyNieWystepuje(Maszyna& _obiekt)const;
	bool sprawdzCzyNieWystepuje(Pole& _obiekt)const;

	void wyczyscGospodarstwo();

	void odczytajMaszynyZPliku(char* sciezka);
    void odczytajPolaZPliku(char* sciezka);

};


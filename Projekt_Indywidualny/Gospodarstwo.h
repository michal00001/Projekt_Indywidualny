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
	//void edytujNazwa(std::deque<Maszyna>::iterator _maszyna);
	void usunMaszyne(int _pozycja);
	void zapiszMaszynyCSV(char* sciezka);

	void wyswietlListeMaszyn();
	void wyswietlListeMaszyn(int _ile);
	void wyswietlListePol();
	void wyswietlListePol(int _ile);


	void dodajPole(Pole _obiekt);
	void edytujPole(std::deque<Pole>::iterator pole, std::string _nazwa, float _powierzchnia);
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


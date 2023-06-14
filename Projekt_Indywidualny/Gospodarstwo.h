#pragma once
#include <vector>
#include "Pole.h"
#include "Maszyna.h"

class Gospodarstwo
{
private:
	std::vector<Pole> ZiemiaUprawna;
	std::vector<Maszyna> ParkMaszynowy;
public:
	void dodajMaszyne();
	void dodajMaszyne(Maszyna _obiekt);

	void usunMaszyne(int _pozycja);

	void dodajPole();
	void dodajPole(Pole _obiekt);

	void usunPole(int _pozycja);

	Maszyna& getMaszyna(int _miejsce);
	Pole& getPole(int _miejsce);

	void wyczyscGospodarstwo();

};


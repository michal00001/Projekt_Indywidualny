#pragma once
#include "Drukarka.h"
#include "Gospodarstwo.h"
#include "Kalendarz.h"

class Interfejs
{
	Gospodarstwo Gospodarstwo;
	Kalendarz KalendarzZabiegow;

	void OpcjaZapisaneMaszyny();
	void OpcjaZapisanePola();
	void OpcjaKalendarzZabiegow();

	void OpcjaDodaj(int _opcja);
	void OpcjaUsun(int _opcja);
	void OpcjaEdytuj(int _opcja);
	void OpcjaWczytaj(int _opcja);
	
	int bezpiecznyInt(int _od, int _do = INT_MAX);
	float bezpiecznyFloat(float _od, float _do = FLT_MAX);
	int MenuWyboru(int& numerek);

	bool czyPozaZakresem(int _opcja, int _indeksTablicy);
	
	void dodawanieMaszyn();
	void dodawaniePol();
	void dodawanieZabiegow();

	Maszyna* wybierzMaszyne(int& numer);
	Pole* wybierzPole();

	Data utworzDataObiekt();
	Pole utworzPoleObiekt();
	void edycjaPol(Pole& _pole);
	void edycjaZabiegow(std::list<Zabieg>::iterator _obiekt);

	string podajSciezke(const char* _rozszerzenie);
public:
	void MenuGlowne();
};


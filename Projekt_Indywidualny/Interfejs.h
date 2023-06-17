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
	
	int podajOpcje(int _od, int _do = 2000000);
	int MenuWyboru(int& numerek);

	bool czyPozaZakresem(int _opcja, int _indeksTablicy);
	
	void dodawanieMaszyn();
	void dodawaniePol();
	//void dodawanieZabiegow();

	Pole wprowadzDane();
	void edycjaPol(std::deque<Pole>::iterator _pole);

public:
	void MenuGlowne();
	
	

};


#pragma once
#include "Kalendarz.h"
#include "Gospodarstwo.h"
#include "Drukarka.h"

class Interfejs
{
	Kalendarz KalendarzZabiegow;
	Gospodarstwo Gospodarstwo;

	void OpcjaKalendarzZabiegow();
	void OpcjaZapisanePola();
	void OpcjaZapisaneMaszyny();

	void OpcjaDodaj(int _opcja);
	void OpcjaUsun(int _opcja);
	void OpcjaEdytuj(int _opcja);
	void OpcjaWczytaj(int _opcja);
	int MenuWyboru(int& numerek);
	bool czyPozaZakresem(int _opcja, int _indeksTablicy);
public:
	void MenuGlowne();
	
	

};

